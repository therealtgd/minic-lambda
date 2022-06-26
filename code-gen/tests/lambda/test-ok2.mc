// RETURN: 4
// Dve lambda funkcije
// Prosledjivanje rezultata prve kao parametar druge
int main() {
    int a;
    int b;
    int c;
    lambda x = lambda(int a, int b) : a - b + 1;
    lambda y = lambda(int ay, int by) : ay + by;
    c = 3;
    b = x -> (3, c); // 3-3+1=1
    a = y -> (3, b); // 3+1=4
    return a;
}