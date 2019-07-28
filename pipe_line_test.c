// 시스템 프로그래밍
// 파이프라인 통신 테스트

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>


int main(void)
{
	int fd[2];
	int input, output, output1;
	int n;
	int status;
	char buf[10];
	int i;

	if(pipe(fd)==-1)  
		exit(1);

	if(fork()==0)  //child 1
	{
		input = open ("input", 0);
		close( fd[0] );
		while ((n= read(input, buf, 10)) != 0)
			write(fd[1], buf, n);

		close(input);
		close(fd[0]);
		exit(0);
	}

	if(fork()==0)  //child2
	{
		close(fd[1]);
		output = creat("output", 0666);

		while((n=read(fd[0],buf,10)) != 0)
			write(output, buf, n);

		for(i=0;i<10;i++)  // make character as Capital letter
		{
			buf[i]=buf[i]-('a'-'A');
		}

		close(output);
		wait(&status);

	}

	else {     //parent

		output1 = creat("output1", 0666);
		close(fd[1]); // Question!!!!!!!!!!! why if this isn't closed the file can't be executed
		while((n=read(fd[0],buf,10)) != 0)
			write(output1, buf, n);

		close(output1);
		wait(&status);
	}
	return 0;
}
