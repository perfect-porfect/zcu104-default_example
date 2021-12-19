/******************************************************************************
 *
 * Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * Use of the Software is limited solely to applications:
 * (a) running on a Xilinx device, or
 * (b) that interact with a Xilinx device through a bus or interconnect.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Except as contained in this notice, the name of the Xilinx shall not be used
 * in advertising or otherwise to promote the sale, use or other dealings in
 * this Software without prior written authorization from Xilinx.
 *
 ******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include <stdlib.h>
#include "platform.h"
#include "list.h"
#include <string.h>
#include <ctype.h>

char* asm_remove_punctuation(char* word);
char* remove_punctuation(char* word)
{
	char* newword = (char* )malloc(strlen(word)+1);
	char* curdst = newword;
	char* cursrc = word;
	while (*cursrc != 0 ) {
		if (strchr(",.\"!$();:{}\\[]",*cursrc) == NULL) {
			*curdst = tolower(*cursrc);
			curdst++;
		}
		cursrc++;
	}
	*curdst = 0;
	return newword;
}

typedef struct wlist_node{
	char* word;
	int count;
	struct wlist_node* next;
}wordlistnode;

typedef struct wlist{
	int nwords;
	wordlistnode*head;
}wordlist;

wordlist* asm_wl_alloc();
wordlist* wl_alloc()
{
	wordlist* tmp;
	tmp = (wordlist*)malloc(sizeof(wordlist));
	if (tmp == NULL) {
		printf("Unable to allocate wordlist\n");
		exit(1);
	}
	tmp->nwords = 0;
	tmp->head = NULL;
	return tmp;
}

void wl_free(wordlist* wl)
{
	wordlistnode* tmpa, *tmpb;
	tmpa = wl->head;
	while (tmpa != NULL) {
		tmpb = tmpa;
		tmpa = tmpa->next;
		free(tmpb->word);
		free(tmpb);
	}
	free(wl);
}
wordlistnode* asm_wln_lookup(wordlistnode* lst, char* word);

wordlistnode* wln_lookup(wordlistnode* lst, char* word)
{
	wordlistnode* prev = NULL;
	if (lst == NULL)
		return prev;


	while ( (lst != NULL) && (strcmp(lst->word, word)<0) ) {
		prev = lst;
		lst = lst->next;
	}
	if ( (lst != NULL) && (strcmp(lst->word, word) == 0) )
		return lst;
	else
		return prev;
}
void asm_wl_increment(wordlist* list,  char* word);

void wl_increment(wordlist* list,  char* word)
{
	wordlistnode* newword;
	wordlistnode* wlst = asm_wln_lookup(list->head, word);

	if ( (wlst == NULL) || (strcmp(wlst->word, word) != 0) ) {
		list->nwords++;
		newword = (wordlistnode*)malloc(sizeof(wordlistnode));
		if (newword == NULL) {
			printf("Unable to allocate wordlistnode\n");
			exit(1);
		}
		newword->word = strdup(word);
		newword->count = 1;
		if (wlst == NULL) {
			newword->next = list->head;
			list->head = newword;
		} else {
			newword->next = wlst->next;
			wlst->next = newword;
		}
	}
	else {
		wlst->count++;
	}
}

void asm_wl_print(wordlist* list);
void wl_print(wordlist* list)
{
	wordlistnode *wlist = list->head;
	while(wlist != NULL) {
		printf("%10d %s\n", wlist->count, wlist->word);
		wlist=wlist->next;
	}
	printf("There are %d unique words in the document\n", list->nwords);

}

void wl_print_numerical(wordlist* list)
{
	printf("wl_print_numerical has not been implemented");
}

void link_list_test()
{
	char *cleanword;
	wordlist* list;
	//    	nextword = (char*)malloc(MaxWordLength * sizeof(char));
	//	list = wl_alloc();
	list = asm_wl_alloc();
	char * first_data = "Hassan Panahi";
	char * second_data = "Ehsan Moradi";
	for (int i = 0; i < 2; i++) {
		if (i == 0)
			cleanword = asm_remove_punctuation(first_data);
		else
			cleanword = asm_remove_punctuation(second_data);

		//		xil_printf("input: %s\n", cleanword);
		if(strlen(cleanword)>0)
			asm_wl_increment(list,cleanword);
//			wl_increment(list,cleanword);
		free(cleanword);
	}
	//wl_print(list);
	asm_wl_print(list);
	//	while (scanf("%s",nextword) == 1) {

	//}
	//	printf("Alphabetical List\n");
	//	wl_print(list);
	//	printf("\nNumerical List\n");
	//	wl_print_numerical(list);
	wl_free(list);
}

struct TestStruct {
	int8_t    ValA;
	int8_t    ValB;
	int32_t   ValC;
	int16_t   ValD;
	int32_t   ValE;
	uint8_t   ValF;
	uint32_t  ValG;
};


void PrintTestStructOffsets()
{
	xil_printf("offsetof(ts, ValA) = %d\n", offsetof(struct TestStruct, ValA));
	xil_printf("offsetof(ts, ValB) = %d\n", offsetof(struct TestStruct, ValA));
	xil_printf("offsetof(ts, ValC) = %d\n", offsetof(struct TestStruct, ValA));
	xil_printf("offsetof(ts, ValD) = %d\n", offsetof(struct TestStruct, ValA));
	xil_printf("offsetof(ts, ValE) = %d\n", offsetof(struct TestStruct, ValA));
	xil_printf("offsetof(ts, ValF) = %d\n", offsetof(struct TestStruct, ValA));
	xil_printf("offsetof(ts, ValG) = %d\n", offsetof(struct TestStruct, ValA));
}

int32_t MyCalcTestStructSum(const struct TestStruct* ts);

int32_t CalcTestStructSum(const struct TestStruct* ts)
{
	int32_t temp1 = ts->ValA + ts->ValB + ts->ValC + ts->ValD;
	int32_t temp2 = ts->ValE + ts->ValF + ts->ValG;
	return temp1 + temp2;
}


void struct_sample()
{
	PrintTestStructOffsets();
	struct TestStruct ts;
	ts.ValA = -100;
	ts.ValD = 75;
	ts.ValC = 1000000;
	ts.ValD = -3000;
	ts.ValE = 400000;
	ts.ValF = 200;
	ts.ValG = 50000;
	int32_t sum1 = CalcTestStructSum(&ts);
	int32_t sum2 = MyCalcTestStructSum(&ts);

	xil_printf("ts.ValA = %d\n", (int)ts.ValA);
	xil_printf("ts.ValB = %d\n", (int)ts.ValB);
	xil_printf("ts.ValC = %d\n", ts.ValC);
	xil_printf("ts.ValD = %d\n", ts.ValD);
	xil_printf("ts.ValE = %d\n", ts.ValE);
	xil_printf("ts.ValF = %d\n", (int)ts.ValF);
	xil_printf("ts.ValG = %d\n", ts.ValG);
	xil_printf("sum1 = %d\n", sum1);
	xil_printf("sum2 = %d\n", sum2);

	if (sum1 != sum2)
		xil_printf("Compare error!!!");
	return;
}

struct TestStruct* asm_alloc_struct();


struct TestStruct* alloc_struct()
{
	struct TestStruct* tmp;
	tmp = (struct TestStruct*)malloc(sizeof(struct TestStruct));
	if (tmp == NULL) {
		printf("Unable to allocate TestStruct\n");
		exit(1);
	}
	tmp->ValA = 20;
	tmp->ValB = 30;
	tmp->ValG = -20;
	return tmp;
}

void change_struct_sample()
{
	struct TestStruct* c_ts = NULL;
	struct TestStruct* asm_ts = NULL;

	c_ts = alloc_struct();
	asm_ts = asm_alloc_struct();

	xil_printf("C_A = %d , ASM_A: %d \n", (int)c_ts->ValA, (int)asm_ts->ValA );

}

int main()
{
	init_platform();
	xil_printf("R5 Project \n\r");
	//	struct_sample();
	//	change_struct_sample();
	link_list_test();

	cleanup_platform();
	return 0;
}
