// Tipovi parametara lambda f-je nisu isti
int main() {
    int b;
    lambda x = lambda(int a, unsigned b) : a + b - 1;
    b = x->(2, 3);    
    return 1;
}