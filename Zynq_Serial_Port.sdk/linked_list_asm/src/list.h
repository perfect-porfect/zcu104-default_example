/*
 * list.h
 *
 *  Created on: Aug 30, 2021
 *      Author: hp
 */

#ifndef SRC_LIST_H_
#define SRC_LIST_H_

typedef struct wlist wordlist;

wordlist* wl_alloc();

void wl_free(wordlist* wl);

void wl_increment(wordlist* list,char* word);

void wl_print(wordlist* list);
void wl_print_numerical(wordlist* list);

#endif /* SRC_LIST_H_ */
