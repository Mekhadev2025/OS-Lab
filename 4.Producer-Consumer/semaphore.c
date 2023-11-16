#include <stdio.h>
#include <stdlib.h>
int mutex = 1;
int full = 0, empty = 5;
int x = 0;
int main()
{
	int ch;
	void producer();
	void consumer();
	printf("***************************************************\n");
	printf("\t\t MENU\t\t \n");
	printf("\t\t----------\t\n\n");
	printf("1.Producer \t\t \n");
	printf("2.Consumer \t\t \n");
	printf("3.Exit \t\t \n");
	printf("***************************************************\n");
	while (1)
	{
		printf("Enter your choice \n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
		{
			if ((mutex == 1) && (empty != 0))
				producer();
			else
				printf("Buffer Full\n");

			break;
		}
		case 2:
		{
			if ((mutex == 1) && (full != 0))
				consumer();
			else
				printf("Buffer Empty \n");
			break;
		}
		case 3:
		{
			exit(0);
			break;
		}
		}
	}
}

int wait(int s)
{
	return (--s);
}
int signal(int s)
{
	return (++s);
}
void producer()
{
	mutex = wait(mutex);
	empty = wait(empty);
	full = signal(full);
	x++;
	printf("The producer produces the item %d \n", x);
	mutex = signal(mutex);
}
void consumer()
{
	mutex = wait(mutex);

	full = wait(full);
	empty = signal(empty);

	printf("The consumer consumes the item %d \n", x);
	x--;
	mutex = signal(mutex);
}
