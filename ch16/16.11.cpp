template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
  List<elemType>();
  List<elemType>(const List<elemType> &);
  List<elemType>& operator=(const List<elemType> &);
  ~List();
  //void insert(ListItem *ptr, elemType value);  // error: should specify type
  void insert(ListItem<elemType> *ptr, elemType value);
private:
  //ListItem *front, *end;  // error: should specify type
  ListItem<elemType> *front, *end;
};

int main() {
  List<int> l;
  return 0;
}
