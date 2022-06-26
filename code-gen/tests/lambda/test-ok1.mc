int main() {
    int a;
    int b;
    int c;
    lambda x = lambda(int a, int b) : a - b + 1;
    b = 2;
    c = 3;
    a = x -> (3, b); // 2
    return a;
}