#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/spinlock.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple kernel module");

static struct task_struct *thread1, *thread2;
static DEFINE_SPINLOCK(lock);

int thread1_func(void *data) {

    // 获取自旋锁
    spin_lock(&lock);
    printk(KERN_INFO "Thread 1 started\n");
    // 模拟线程1释放自旋锁给线程2
    for(int i = 1; i < 100; i++) printk("%d ", i);
    printk("\n");
    printk(KERN_INFO "Thread 1 released the spinlock\n");
    spin_unlock(&lock);

    return 0;
}

int thread2_func(void *data) {

    // 尝试获取自旋锁，但线程1还未释放
    if(!spin_trylock(&lock)) spin_unlock(&lock);
    spin_lock(&lock);
    printk(KERN_INFO "Thread 2 started\n");

    printk(KERN_INFO "Thread 2 acquired the spinlock\n");
    spin_unlock(&lock);

    return 0;
}

static int __init my_module_init(void) {
    printk(KERN_INFO "Initializing the kernel module\n");

    // 创建线程1和线程2
    thread1 = kthread_create(thread1_func, NULL, "my_thread1");
    thread2 = kthread_create(thread2_func, NULL, "my_thread2");

    // 启动线程1和线程2
    kthread_bind(thread1, 0);  // 绑定到CPU 0
    kthread_bind(thread2, 1);  // 绑定到CPU 1
    wake_up_process(thread1);
    wake_up_process(thread2);

    return 0;
}

static void __exit my_module_exit(void) {

    printk(KERN_INFO "Exiting the kernel module\n");
}

module_init(my_module_init);
module_exit(my_module_exit);
