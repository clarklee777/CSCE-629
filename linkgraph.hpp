/* Header file to declare functions for random generate graph */

struct vertices{
    struct vertices *next;
    //vertices *prev;
    int v_num;
};

class linked_list{
private:
    struct vertices *head, *tail;
    
public:
    /* Initialize the list */
    list()
    {
        head = NULL;
        tail = NULL;
    }
    void insert(struct vertices *vertex);
    {
        struct vertices *temp = vertex;
        if(head==NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    bool find_edge(int vertex_num);
    {
        struct vertices *temp = new struct vertices;
        temp = head;
        while(temp->next!=NULL)
        {
            if(temp->next==vertex_num) return true;
            else temp = temp->next;
        }
        return false;
    }
    
    
    
};