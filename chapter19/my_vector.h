// an almost real vector of doubles:
template <typename T>
class vector
{
    /*
    invariant:
    if 0<=n<sz, elem[n] is element n
    sz<=space;
    if sz<space there is space for (space–sz) doubles after elem[sz–1]
    */
    int sz;    // the size
    T *elem;   // pointer to the elements (or 0)
    int space; // number of elements plus number of free slots
  public:
    vector() : sz{0}, elem{nullptr}, space{0} {}
    explicit vector(int s) : sz{s}, elem{new T[s]}, space{s}
    {
        for (int i = 0; i < sz; ++i)
            elem[i] = 0; // elements are initialized
    }
    vector(const vector &);                  // copy constructor
    vector &operator=(const vector &);       // copy assignment
    vector(vector &&);                       // move constructor
    vector &operator=(vector &&);            // move assignment
    ~vector() { delete[] elem; }             // destructor
    T &operator[](int n) { return elem[n]; } // access: return reference
    const T &operator[](int n) const { return elem[n]; }
    int size() const { return sz; }
    int capacity() const { return space; }
    void resize(int newsize); // growth
    void push_back(const T &d);
    void reserve(int newalloc);
};
