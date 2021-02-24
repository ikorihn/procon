#include <bits/stdc++.h>
using namespace std;

struct Node {
  int key;
  Node *prev, *next;
};

Node *nil;

Node *listSearch(int key) {
  Node *cur = nil->next;
  while (cur != nil && cur->key != key) {
    cur = cur->next;
  }
  return cur;
}

void init() {
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

void printList() {
  Node *cur = nil->next;
  int isf = 0;
  while (true) {
    if (cur == nil) break;
    if (isf++ > 0) printf(" ");
    printf("%d", cur->key);
    cur = cur->next;
  }
  printf("\n");
}

void deleteNode(Node *t) {
  if (t == nil) return;
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

void deleteFirst() { deleteNode(nil->next); }
void deleteLast() { deleteNode(nil->prev); }
void deleteKey(int k) { deleteNode(listSearch(k)); }

void insert(int key) {
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  // 番兵の直後に挿入
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

int main() {
  int N;
  cin >> N;
  vector<pair<string, int>> commands(N);
  for (int i = 0; i < N; i++) {
    string s;
    int a;
    cin >> s >> a >> endl;
    commands.at(i) = make_pair(s, a);
  }
  return 0;
}