package main

import (
	"fmt"
	"net/http"

	"github.com/prometheus/client_golang/prometheus"
	"github.com/prometheus/client_golang/prometheus/promhttp"
)

func main() {
	registry := prometheus.NewRegistry()
	// registry.MustRegister(collectors.NewProcessCollector(collectors.ProcessCollectorOpts{}))
	// registry.MustRegister(collectors.NewGoCollector())
	// 创建一个没有任何 label 标签的 gauge 指标
	temp := prometheus.NewGauge(prometheus.GaugeOpts{
		Name: "home_temperature_celsius",
		Help: "The current temperature in degrees Celsius.",
	})
	// 设置 gauge 的值为 39
	temp.Set(39)

	queueLength := prometheus.NewGauge(prometheus.GaugeOpts{
		Name: "queue_length",
		Help: "The number of items in the queue.",
	})
	// 使用 Set() 设置指定的值
	queueLength.Set(0)
	// 增加或减少
	queueLength.Inc()   // +1：gauge增加1.
	queueLength.Dec()   // -1：gauge减少1.
	queueLength.Add(23) // 增加23个增量.
	queueLength.Sub(42) // 减少42个.

	totalRequests := prometheus.NewCounter(prometheus.CounterOpts{
		Name: "http_requests_total",
		Help: "The total number of handled HTTP requests.",
	})
	totalRequests.Inc()   // +1：计数器增加1.
	totalRequests.Add(23) // +n：计数器增加23.

	requestDurations := prometheus.NewHistogram(prometheus.HistogramOpts{
		Name: "Histogram_http_request_duration_seconds",
		Help: "A histogram of the HTTP request durations in seconds.",
		// Bucket 配置：第一个 bucket 包括所有在 0.05s 内完成的请求，最后一个包括所有在10s内完成的请求。
		Buckets: []float64{0.05, 0.1, 0.25, 0.5, 1, 2.5, 5, 10},
	})
	requestDurations.Observe(0.42)
	// 启动一个计时器
	timer := prometheus.NewTimer(requestDurations)
	// [...在应用中处理请求...]
	fmt.Println("Histogram test.")
	// 停止计时器并观察其持续时间，将其放进 requestDurations 的直方图指标中去
	timer.ObserveDuration()

	requestDurations2 := prometheus.NewSummary(prometheus.SummaryOpts{
		Name: "Summary_http_request_duration_seconds",
		Help: "A summary of the HTTP request durations in seconds.",
		Objectives: map[float64]float64{
			0.5:  0.05,  // 第50个百分位数，最大绝对误差为0.05。
			0.9:  0.01,  // 第90个百分位数，最大绝对误差为0.01。
			0.99: 0.001, // 第99个百分位数，最大绝对误差为0.001。
		},
	},
	)
	requestDurations2.Observe(0.42)

	temp2 := prometheus.NewGaugeVec(
		prometheus.GaugeOpts{
			Name: "labeled_home_temperature_celsius",
			Help: "The current temperature in degrees Celsius.",
		},
		// 两个标签名称，通过它们来分割指标。
		[]string{"house", "room"},
	)
	// 为 home=ydzs 和 room=living-room 设置指标值
	temp2.With(prometheus.Labels{"house": "schf", "room": "living-room"}).Set(66)
	// 针对不同标签值设置不同的指标值
	temp2.WithLabelValues("cnych", "living-room").Set(27)
	temp2.WithLabelValues("cnych", "bedroom").Set(25.3)
	temp2.WithLabelValues("ydzs", "living-room").Set(24.5)
	temp2.WithLabelValues("ydzs", "bedroom").Set(27.7)

	// 在默认的注册表中注册该指标
	registry.MustRegister(temp, temp2, queueLength, totalRequests, requestDurations, requestDurations2)

	// 暴露指标
	http.Handle("/metrics", promhttp.HandlerFor(registry, promhttp.HandlerOpts{Registry: registry}))
	http.ListenAndServe(":8080", nil)
}
