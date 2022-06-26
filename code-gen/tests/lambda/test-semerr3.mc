// Tipovi argumenata nisu isti kao tipovi parametara lambda f-je
int main() {
    int b;
    unsigned e;
    unsigned f;
    lambda x = lambda(int a, int b) : a + b - 1;
    e = 1;
    f = 2;
    b = x->(e, f);    
    return 1;
}