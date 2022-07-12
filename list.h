
struct node{
  int element;
  node* p_dir;
};

class list{

  public:
    list(){}
    /* ~nlist(); */
    void append (int val);
    void insert (int index, int val);
    void print();
    void supr(int index);

  private:
    node* p_first;

};
