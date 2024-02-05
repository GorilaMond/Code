#include <stdio.h>
#include <string.h>
#define abs(a) (a >= 0 ? a:-a)
int main(int argc, char const **argv) {
	int n;
	scanf("%d",&n);
	char left[7], right[7], result[5], realCoin[12], temp[12];
	while(n--) {
		memset(realCoin, 0, sizeof(realCoin));
		memset(temp, 0, sizeof(temp));
		for(int i = 0; i < 3; i++) {
			scanf("%s %s %s", left, right, result);
			if(!strcmp(result, "even")) {
				for(int j = 0; left[j]; j++) {
					realCoin[left[j]-'A'] = 1;
				}
				for(int j = 0; right[j]; j++) {
					realCoin[right[j]-'A'] = 1;
				}
			} else if(!strcmp(result, "up")) {
				for(int j = 0; left[j]; j++) {
					temp[left[j]-'A']++;
				}
				for(int j = 0; right[j]; j++) {
					temp[right[j]-'A']--;
				}
			} else {
				for(int j = 0; left[j]; j++) {
					temp[left[j]-'A']--;
				}
				for(int j = 0; right[j]; j++) {
					temp[right[j]-'A']++;
				}
			}
		}
		int k = -1, ans = 0, flag = 0;
		for(int i = 0; i < 12; i++) {
			if(realCoin[i]) {
				continue;
			}
			if(k < abs(temp[i])) {
				k = abs(temp[i]);
				ans = i;
				flag = temp[i];
			}
		}
		printf("%c is the counterfeit coin and it is %s.\n", ans+'A', flag>0?"heavy":"light");
	} 
	return 0;
}
