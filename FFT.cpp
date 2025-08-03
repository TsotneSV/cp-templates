#define cmpl complex<double>
#define vc vector<cmpl>
const double PI = acos(-1.0);

vc DFT(vc P) {
    
    int n = P.size();

    if(n == 1) {
        return P;
    }

    vc P_even(n/2),P_odd(n/2);

    for(int i=0;i<n/2;i++) {
        P_even[i] = P[2 * i];
        P_odd[i] = P[2 * i + 1];
    }

    vc D_even = DFT(P_even),D_odd = DFT(P_odd),D(n);

    for(int j=0;j<n/2;j++) {
        cmpl wj = exp(2 * PI * j * cmpl(0,1) / cmpl(n,0));
        D[j] = D_even[j] + wj * D_odd[j];
        D[j + n/2] = D_even[j] - wj * D_odd[j];
    } 
    
    return D;
}

vc interpolation(vc C) {

    int n = C.size();

    if(n == 1) {
        return C;
    }

    vc D_even(n/2),D_odd(n/2),P(n);

    for(int j=0;j<n/2;j++) {
        cmpl wj = exp(2 * PI * j * cmpl(0,1) / cmpl(n,0));
        D_even[j] = (C[j] + C[j+n/2]) / cmpl(2,0);
        D_odd[j] = (C[j] - D_even[j]) / wj;
    }

    vc P_even = interpolation(D_even),P_odd = interpolation(D_odd);

    for(int i=0;i<n/2;i++) {
        P[2 * i] = P_even[i];
        P[2 * i + 1] = P_odd[i];
    } return P;

}

vector<ll> multiply(vector<ll> A,vector<ll> B) {

    int n = 1;

    while(n < A.size() + B.size() - 1) {
        n *= 2;
    }

    vc cA(n,0),cB(n,0);

    copy(A.begin(),A.end(),cA.begin());
    copy(B.begin(),B.end(),cB.begin());

    vc dA = DFT(cA),dB = DFT(cB);
    
    vc dC(n);

    for(int i=0;i<n;i++) dC[i] = dA[i] * dB[i];

    vc C = interpolation(dC); vector<ll> ans(n);

    for(int i=0;i<n;i++) ans[i] = round(C[i].real());

    return ans;
}
