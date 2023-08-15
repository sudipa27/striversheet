//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node* p=head;
        vector<int> arr;
        while(p!=NULL)
        {
          arr.push_back(p->data);
          p=p->next;
        }
        int start=0,mid=0, end =arr.size()-1;
        while(mid<=end)
        {
            switch (arr[mid])
            {
                case 0:
                {
                swap(arr[start++],arr[mid++]);
                break;
                }
                case 1:
                {
                    mid++;
                    break;
                }
                case 2:
                {
                    swap(arr[mid],arr[end--]);
                    break;
                }
                
            }
    
        }
    Node* h = new Node(0);
    Node* ptr= h;
    for(int i=0;i<arr.size();i++)
    {
        Node *x= new Node(arr[i]);
        ptr->next = x;
        ptr=ptr->next;
    }
    return h->next;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends