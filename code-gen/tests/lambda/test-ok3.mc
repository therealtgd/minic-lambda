// RETURN: 1
// Jedna lambda funkcija sa jednim parametrom
int main() {
    int res;
    lambda x = lambda(int a) : a;
    res = x -> (1); // 1
    return res;
}