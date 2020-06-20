#define matrix vector<vector<int>>

const int N = 26;

matrix get(int n = N) {
    return vector<vector<int>> (n, vector<int> (n, 0));
}

matrix identity() {
    matrix a = get();
    for (int i = 0; i < N; i++)
        a[i][i] = 1;
    return a;
}        

matrix mult(matrix a, matrix b) {
    matrix c = get();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
    return c;
}

matrix powers[26];

matrix power(int n) {
    matrix c = identity();
    int curr = 0;
    while (n) {
        if (n & 1)
            c = mult(c, powers[curr]);
        curr++;
        n /= 2;
    }
    return c;
}

void precomp(matrix base) {
    powers[0] = base;
    for (int i = 1; i < 26; i++)
        powers[i] = mult(powers[i - 1], powers[i - 1]);
}
