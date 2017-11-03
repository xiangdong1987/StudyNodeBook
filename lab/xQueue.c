#include <sys/queue.h>
#include <stdio.h>
#include <stdlib.h>

//定义队列结构体
struct xItem{
	int value;
	TAILQ_ENTRY(xItem) entries;
};
//初始化队列头
TAILQ_HEAD(,xItem) queue_head;
int main(void){
	struct xItem *item;
	struct xItem *tmpItem;
	//初始化队列
	TAILQ_INIT(&queue_head);
	int i=0;
	for(i=5;i<10;i+=2){
		item=malloc(sizeof(item));
		item->value=i;
		//向队列中插入一个元素
		TAILQ_INSERT_TAIL(&queue_head,item,entries);
	}
	struct xItem *ins_item;
	ins_item=malloc(sizeof(ins_item));
	ins_item->value=100;
	//在某个元素前插入一个元素
	TAILQ_INSERT_BEFORE(item,ins_item,entries);
	//只想队列前头
	tmpItem=TAILQ_FIRST(&queue_head);
	printf("first element is %d\n",tmpItem->value);
	//移动到下个元素
	tmpItem=TAILQ_NEXT(tmpItem,entries);
	printf("next element is %d\n",tmpItem->value);

	//删除一个元素
	TAILQ_REMOVE(&queue_head,tmpItem,entries);

	tmpItem=TAILQ_NEXT(tmpItem,entries);
	printf("next element is %d\n",tmpItem->value);

	tmpItem=TAILQ_NEXT(tmpItem,entries);
	printf("next element is %d\n",tmpItem->value);

	//指向队列前头
	tmpItem=TAILQ_FIRST(&queue_head);
	printf("first element is %d\n",tmpItem->value);
	//移动到下个元素
	tmpItem=TAILQ_NEXT(tmpItem,entries);
	printf("next element is %d\n",tmpItem->value);

	tmpItem=TAILQ_NEXT(tmpItem,entries);
	printf("next element is %d\n",tmpItem->value);

	tmpItem=TAILQ_NEXT(tmpItem,entries);
	printf("next element is %d\n",tmpItem->value);
}
