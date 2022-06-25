int main() {
    int a;
    int b;
    int c;
    lambda x = lambda(int b, int a) : a - b + 1;
    lambda y = lambda(int by, int ay) : ay - by + 1;
    b = 2;
    c = 3;
    a = x -> (3, b);
    return a;
}