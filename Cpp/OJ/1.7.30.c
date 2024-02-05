#include <stdio.h>
#include <string.h>
#define SIZE 255

// // Time Limit Exceeded
// int main(void) {
//     char Astr[SIZE], Bstr[SIZE];
//     unsigned Ai, Bi, maxlen=0, tmplen, Alen, Blen, Bhop[SIZE], i;
//     scanf("%s %s", Astr, Bstr);
//     Alen=strlen(Astr); Blen=strlen(Bstr);
//     for(i=0; i<Blen; i++) {
//         for(tmplen=1; tmplen<Blen && Bstr[i]!=Bstr[(i+tmplen)%Blen]; tmplen++);
//         if(tmplen!=Blen) Bhop[i]=(i+tmplen)%Blen;
//         else Bhop[i]=i;
//     }
//     for(Ai=0; Ai<Alen; Ai++) {
//         for(Bi=0; Bi<Blen && Astr[Ai]!=Bstr[Bi]; Bi++);
//         if(Bi!=Blen) {
//             i=Bi;
//             do {
//                 for(tmplen=1; Bstr[(Bi+tmplen)%Blen]==Astr[(Ai+tmplen)%Alen]; tmplen++);
//                 if(tmplen > maxlen) maxlen = tmplen;
//                 Bi=Bhop[Bi];
//             } while(Bi!=i);
//         }
//     }
//     printf("%d\n", maxlen);
//     return 0;
// }

int main(void) {
    char Astr[SIZE*2+1], Bstr[SIZE*2+1];
    unsigned Ai, Bi, maxlen=0, tmplen, Alen, Blen, limit;
    scanf("%s %s", Astr, Bstr);
    Alen=strlen(Astr); Blen=strlen(Bstr);
    strcpy(Astr+Alen, Astr); strcpy(Bstr+Blen, Bstr);
    limit = Alen > Blen ? Blen : Alen;
    for(Ai=0;Ai<Alen;Ai++)
        for(Bi=0;Bi<Blen;Bi++) {
            for(tmplen=0;tmplen<limit && Astr[Ai+tmplen]==Bstr[Bi+tmplen]; tmplen++);
            if(tmplen>maxlen) maxlen=tmplen;
        }
    printf("%d\n", maxlen);
    return 0;
}