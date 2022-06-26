// RETURN: 1
// definicija dva enuma
int main() {
    int a;
    int b;
    int c;
    enum state {started, finished};
    enum rating {bronze, silver, gold};
    a = state.started;
    b = rating.silver;
    c = a + b;
    return c;
}