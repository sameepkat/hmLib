#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
  char* token;
  struct Node* next;
}Node;

Node* head = NULL;
void push(char* str)
{
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->token = (char *)malloc(strlen(str)+1);
  strcpy(temp->token, str);
  temp->next = NULL;
  if(!head)
  {
  head = temp;
  } else{
  Node* current = head;
  while(current->next)
  {
    current = current->next;
  }
  current->next = temp;
}
}

void token_print()
{
  Node* current = head;
  printf("List:\n");
  while (current) {
    printf("%s\n",current->token);
    current = current->next;
  }
}

int size_of(Node* h)
{
  int count = 0;
  Node* it = h;
  while(it){
    count++;
    it = it->next;
  }
  return count;
}

Node* tokenize(const char* string, const char delimiter)
{
  int count=1, i = 0, no_of_delimiter=0;
  while(string[i]!='\0')
  {
    if(string[i]==delimiter){
      no_of_delimiter++;
    }
    i++;
  }
  i=0;
  if(no_of_delimiter==0)
  {
    char* token;
    token = (char *)malloc(strlen(string)*sizeof(char));
    strcpy(token, string);
    push(token);
    return NULL;
  }
  while(string[i]!=delimiter)
  {
    if(string[i]=='\0' && no_of_delimiter==0){
      return NULL;
    }
    count++;
    i++;
  }
  char* word = (char *)malloc(count * sizeof(char));
  i=0;
  while(i<count){
    if(i<count-1) word[i] = string[i];
    else word[i] = '\0';
    i++;
  }
  push(word);
  char* remaining_string;
  i=count;
  int remaining_string_count=0;
  while(string[i]!='\0')
  {
    remaining_string_count++;
    i++;
  }
  remaining_string = (char *)malloc(sizeof(char)*remaining_string_count);
  i = 0;
  int j = count;
  while(string[i]!='\0')
  {
    remaining_string[i] = string[j];
    i++;
    j++;
  }
  tokenize(remaining_string, delimiter);
  return head;
}

