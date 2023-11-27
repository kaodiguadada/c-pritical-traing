#include<stdio.h>
#include <string.h>
#include <stdbool.h>

// 完成判断句子是否为全字母句的函数
int checkIfPangram(char * sentence) {
    int hash[256];
    memset(hash, 0, sizeof(hash));
    for(int i = 0; sentence[i]; i++)//空字符串停止
    {
        ++hash[sentence[i]];//对每个字符进行计数
    }
    for(int i = 'a'; i <= 'z'; i++)
    {
        if(hash[i] == 0)
            return false;
    }
    return true;
}

int main(){
	char * sentence1 = "thequickbrownfoxjumpsoverthelazydog";
	printf("输入：sentence = \"thequickbrownfoxjumpsoverthelazydog\"\n");
	if(checkIfPangram(sentence1)){
		printf("输出：true\n");
	}else{
		printf("输出：false\n");
	}
	char * sentence2 = "leetcode";
	printf("输入：sentence = \"leetcode\"\n");
	if(checkIfPangram(sentence2)){
		printf("输出：true\n");
	}else{
		printf("输出：false\n");
	}
	return 0;
}
