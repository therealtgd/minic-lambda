// vrednost enum promenljive nije tipa int
enum state {started, finished};
enum condition {used, new};
int main() {
    unsigned a;
    a = state.started;
    return a;
}