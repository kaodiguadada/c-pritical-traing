#include<stdio.h>
#include <string.h>
#include <stdbool.h>

// ����жϾ����Ƿ�Ϊȫ��ĸ��ĺ���
int checkIfPangram(char * sentence) {
    int hash[256];
    memset(hash, 0, sizeof(hash));
    for(int i = 0; sentence[i]; i++)//���ַ���ֹͣ
    {
        ++hash[sentence[i]];//��ÿ���ַ����м���
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
	printf("���룺sentence = \"thequickbrownfoxjumpsoverthelazydog\"\n");
	if(checkIfPangram(sentence1)){
		printf("�����true\n");
	}else{
		printf("�����false\n");
	}
	char * sentence2 = "leetcode";
	printf("���룺sentence = \"leetcode\"\n");
	if(checkIfPangram(sentence2)){
		printf("�����true\n");
	}else{
		printf("�����false\n");
	}
	return 0;
}
