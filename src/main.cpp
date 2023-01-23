#include<bits/stdc++.h>
using namespace std;



double operation(double x, double y, int k){

    if(k == 0) return x + y;
    else if(k == 1) return x - y;
    else if(k == 2) return x * y;
    else return x / y;
}

int op(int k){
    if(k == 0) return '+';
    else if(k == 1) return '-';
    else if(k == 2) return '*';
    else return '/';
}

void intToString(int k, string *s){
    if(k == 0) *s = "+";
    else if(k == 1) *s = "-";
    else if(k == 2) *s = "*";
    else *s = "/";
}

bool isValid(string s){
    if(s.length() == 1){
        if(s[0] >= '2' and s[0] <= '9'){
            return true;
        }
        else if(s[0] == 'A' or s[0] == 'J' or s[0] == 'Q' or s[0] == 'K'){
            return true;
        }
        else{
            return false;
        }
    }
    else if(s.length() == 2){
        if(s[0] == '1' and s[1] == '0'){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int stringToInt(string s){
    if(s == "A"){
        return 1;
    }
    else if(s[0] == '1' and s[1] == '0'){
        return 10;
    }
    else if(s[0] == 'J'){
        return 11;
    }
    else if(s[0] == 'Q'){
        return 12;
    }
    else if(s[0] == 'K'){
        return 13;
    }
    else{
        return s[0] - '0';
    }
}

int main(){
    while(true){
        cout << "Selamat datang di 24 Game\n";
        cout << "Pilih menu :\n";
        cout << "1. Input 4 kartu\n";
        cout << "2. Generate 4 kartu secara random\n";
        cout << "3. Keluar\n";
        int n;
        cin>>n;
        while(n != 1 and n != 2 and n != 3){
            cout << "\n\nInput tidak valid\n\n";
            cout << "Pilih menu :\n";
            cout << "1. Input 4 kartu\n";
            cout << "2. Generate 4 kartu secara random\n";
            cout << "3. Keluar\n";
            cout << "Masukkan pilihan : ";
            cin >> n;
        }

        string s1,s2,s3,s4;
        int card[4];
        if(n==1 or n==2){
            if(n==1){
                cout << "Masukkan 4 kartu : ";
                cin >> s1 >> s2 >> s3 >> s4;
                while(!isValid(s1) or !isValid(s2) or !isValid(s3) or !isValid(s4)){
                    cout << "Input tidak valid\n";
                    cout << "Masukkan 4 kartu: ";
                    cin >> s1 >> s2 >> s3 >> s4;
                }
                card[0] = stringToInt(s1);
                card[1] = stringToInt(s2);
                card[2] = stringToInt(s3);
                card[3] = stringToInt(s4);
            }
            else if(n == 2){
                for(int i=0; i<4; i++){
                    card[i] = rand() % 13 + 1;
                }
                cout << "Kartu yang terpilih :";
                for(int i=0; i<4; i++){
                    if(card[i] == 1){
                        cout << " A";
                    }
                    else if(card[i] == 11){
                        cout << " J";
                    }
                    else if(card[i] == 12){
                        cout << " Q";
                    }
                    else if(card[i] == 13){
                        cout << " K";
                    }
                    else{
                        cout << " " << card[i];
                    }
                }
                cout << endl;
            }
                int total = 0;
                string operationRes[6969] = {};
                sort(card, card+4);
                auto start = chrono::steady_clock::now();
                do{
                    for(int i=0; i<4; i++){   
                        for(int j=0; j<4; j++){
                            for(int k=0; k<4; k++){
                                string op1,op2,op3;
                                intToString(i, &op1);
                                intToString(j, &op2);
                                intToString(k, &op3);
                                // cout << op3 << endl;

                                // ((card op card) op card) op card
                                if(operation(operation(operation(card[0], card[1], i), card[2], j), card[3], k) == 24){
                                    total++;
                                    operationRes[total] = "((" + to_string(card[0]) + " " + op1 + " " + to_string(card[1]) + ") " + op2 + " " + to_string(card[2]) + ") " + op3 + " " + to_string(card[3]);
                                }
                                // (card op (card op card)) op card
                                if(operation(operation(card[0], operation(card[1], card[2], j), i), card[3], k) == 24){
                                    total++;
                                    operationRes[total] = "(" + to_string(card[0]) + " " + op1 + " (" + to_string(card[1]) + " " + op2 + " " + to_string(card[2]) + ")) " + op3 + " " + to_string(card[3]);
                                }
                                // (card op card) op (card op card)
                                if(operation(operation(card[0], card[1], i), operation(card[2], card[3], k), j) == 24){
                                    total++;
                                    operationRes[total] = "(" + to_string(card[0]) + " " + op1 + " " + to_string(card[1]) + ") " + op2 + " (" + to_string(card[2]) + " " + op3 + " " + to_string(card[3]) + ")";
                                }
                                // card op ((card op card) op card)
                                if(operation(card[0], operation(operation(card[1], card[2], j), card[3], k), i) == 24){
                                    total++;
                                    operationRes[total] = to_string(card[0]) + " " + op1 + " ((" + to_string(card[1]) + " " + op2 + " " + to_string(card[2]) + ") " + op3 + " " + to_string(card[3]) + ")";
                                }
                            }
                        }
                    }
                }while(next_permutation(card, card+4));

                auto end = chrono::steady_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

                if(total == 0){
                    cout << "Tidak ada solusi\n";
                }
                else{
                    cout<< "Jumlah solusi: " << total << "\n";
                    cout << "Solusi: \n";
                    for(int i = 1; i <= total; i++){
                        cout << operationRes[i] << "\n";
                    }
                    cout<< "\nWaktu eksekusi program : " << duration.count() << " mikrosekon\n";
                }
            cout << "Apakah anda ingin menyimpan hasil pencarian ke dalam file? (y/n) ";
            char c;
            cin >> c;
            while(c != 'y' and c != 'n'){
                cout << "Input tidak valid\n";
                cout << "Apakah anda ingin menyimpan hasil pencarian ke dalam file? (y/n) ";
                cin >> c;
            }
            if(c == 'y'){
                ofstream file;
                string namafile;
                cout << "Masukkan nama file: ";
                cin >> namafile;
                namafile += ".txt";
                file.open(namafile);
                file << "Kartu yang terpilih :";
                for(int i=0; i<4; i++){
                    if(card[i] == 1){
                        file << " A";
                    }
                    else if(card[i] == 11){
                        file << " J";
                    }
                    else if(card[i] == 12){
                        file << " Q";
                    }
                    else if(card[i] == 13){
                        file << " K";
                    }
                    else{
                        file << " " << card[i];
                    }
                }
                file << "\n";
                if(total == 0){
                    file << "Tidak ada solusi\n";
                }
                else{
                    file << "Jumlah solusi: " << total << "\n";
                    file << "Solusi: \n";
                    for(int i = 1; i <= total; i++){
                        file << operationRes[i] << "\n";
                    }
                }
                file << "\nWaktu eksekusi program : " << duration.count() << " mikrosekon";
                file.close();
            }
            else{
                cout << "Hasil pencarian tidak disimpan\n";
            }
            cout << "Apakah anda ingin melanjutkan permainan? (y/n) ";
            char c2;
            cin >> c2;
            while(c2 != 'y' and c2 != 'n'){
                cout << "Input tidak valid\n";
                cout << "Apakah anda ingin melanjutkan permainan? (y/n) ";
                cin >> c2;
            }
            if(c2 == 'n'){
                cout << "Terima kasih telah bermain\n";
                return 0;
            }
        }
        else if(n == 3){
            cout << "Terima kasih telah bermain\n";
            return 0;
        }
    }
}