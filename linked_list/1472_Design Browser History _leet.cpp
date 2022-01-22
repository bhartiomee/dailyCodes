class BrowserHistory
{
public:
  struct Node
  {
    string url;
    Node *prev;
    Node *next;
    Node(string data)
    {
      this->url = data;
      next = nullptr;
      prev = nullptr;
    }
  };
  Node *curr = nullptr;

  BrowserHistory(string homepage)
  {
    Node *home = new Node(homepage);
    curr = home;
  }

  void visit(string url)
  {
    Node *tmp = new Node(url);
    tmp->prev = curr;
    curr->next = tmp;
    curr = tmp;
  }

  string back(int steps)
  {
    while (steps-- && curr->prev)
    {
      curr = curr->prev;
    }
    return curr->url;
  }

  string forward(int steps)
  {
    while (steps-- && curr->next)
    {
      curr = curr->next;
    }
    return curr->url;
  }
};
