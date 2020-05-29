//
// Created by rkv on 21/05/2020.
//
#include <bits/stdc++.h>

#include "Book.h"
#include "HardCopy.h"
#include "SoftCopy.h"


stringstream tg1() {
    stringstream letscheck;
    Book* books[8];
    // Create HardCopies and SoftCopies
    books[0] = new HardCopy(120, 30.5);
    books[1] = new SoftCopy(130, 20.2, 0, 100);
    books[2] = new HardCopy(150, 60.75);
    books[3] = new HardCopy(170, 15.1);
    books[4] = new HardCopy(180, 18.3);
    books[5] = new HardCopy(190, 25.5);
    books[6] = new SoftCopy(200, 10.5, 0, 85);
    books[7] = new SoftCopy(160, 50.0, 0, 9);

    /************************ Compare book ISBNs ************************/
    // Operator <
    letscheck << (*books[0] < 150) << endl;    // 120 < 150 ?
    letscheck << (*books[0] < 100) << endl;    // 120 < 100 ?

    // Operator >
    letscheck << (*books[3] > 160) << endl;    // 170 > 160 ?
    letscheck << (*books[3] > 180) << endl;    // 170 > 180 ?

    // Operator < , comparison with another book
    letscheck << (*books[1] < *books[2]) << endl;    // 130 < 150 ?
    letscheck << (*books[2] < *books[1]) << endl;    // 150 < 130 ?

    // Check equality
    letscheck << (*books[2] < 150) << endl;    // 150 < 150 ?
    letscheck << (*books[2] > 150) << endl;    // 150 < 150 ?

    HardCopy temp(150, 10.0);
    letscheck << (*books[2] < temp) << endl;   // 150 < 150 ?

    /************************** Discount() Tests **************************/

    // HardCopy discount
    books[5]->Discount();   // new price: 22.95

    // SoftCopy discount
    books[6]->Discount();   // new price: 7.875

    for(int i = 0; i < 8; i++)
        letscheck << books[i]->GetPrice() << endl;

    /************************ Delete the books ************************/
    for (int i=0; i < 8; i++) {
        if (books[i] != NULL) {
            delete books[i];
            books[i] = NULL;
        }
    }
    return letscheck;

}


stringstream tg2() {
    stringstream letscheck;
    /************************ Construct the books ************************/

    // Create SoftCopies
    SoftCopy* s1 = new SoftCopy(240, 12.0, 0, 18);
    SoftCopy* s2 = new SoftCopy(240, 8.6, 10, 14);
    SoftCopy* s3 = new SoftCopy(240, 17.0, 4, 6);

    SoftCopy* r1 = new SoftCopy(220, 15.0, 0, 7);
    SoftCopy* w1 = new SoftCopy(250, 45.8, 0, 1025);    // Large book

    /********************* Prepare softcopy page content ******************/
    string s_pages[20];
    for (int i=0; i<20; i++) {
        string part1 = "PAGE CONTENT ";
        string part2 = ", in SOFT COPY 240";
        s_pages[i] = part1 + to_string(i) + part2;
    }

    string r_pages[8];
    for (int i=0; i<8; i++) {
        string part1 = "PAGE CONTENT ";
        string part2 = ", in SOFT COPY 220";
        r_pages[i] = part1 + to_string(i) + part2;
    }

    string w_pages[8];
    int w_page_ids[8] = {825, 417, 100, 9, 310, 781, 615, 986};
    for (int i=0; i<8; i++) {
        string part1 = "PAGE CONTENT ";
        string part2 = ", in SOFT COPY 250";
        w_pages[i] = part1 + to_string(w_page_ids[i]) + part2;
    }

    /************************** UploadPage() Tests ***********************/
    // Upload all pages of r1, build full tree
    for (int i=0; i<8; i++)
        r1->UploadPage(r_pages[i], i);

    // Upload specific pages of s1
    s1->UploadPage(s_pages[0], 0);
    s1->UploadPage(s_pages[3], 3);
    s1->UploadPage(s_pages[17], 17);

    // Upload specific pages of s2
    s2->UploadPage(s_pages[10], 10);
    s2->UploadPage(s_pages[11], 11);
    s2->UploadPage(s_pages[12], 12);
    s2->UploadPage(s_pages[13], 13);
    s2->UploadPage(s_pages[14], 14);

    // Upload specific pages of s3
    s3->UploadPage(s_pages[4], 4);
    s3->UploadPage(s_pages[5], 5);
    s3->UploadPage(s_pages[6], 6);

    // Upload specific pages of w1
    for (int i=0; i<8; i++)
        w1->UploadPage(w_pages[i], w_page_ids[i]);

    /************************ Delete the softcopies ***********************/
    letscheck << *s1 << *s2 << *s3 << *r1 << *w1 << endl;
    delete s1;  s1 = NULL;
    delete s2;  s2 = NULL;
    delete s3;  s3 = NULL;
    delete r1;  r1 = NULL;
    delete w1;  w1 = NULL;
    return letscheck;
}

stringstream tg3() {
    stringstream letscheck;

    /************************ Construct the books ************************/
    // Create SoftCopies
    SoftCopy* s1 = new SoftCopy(340, 12.0, 0, 18);      // 19 sayfalık kitap
    SoftCopy* s2 = new SoftCopy(340, 8.6, 10, 14);      // 5 sayfalık parça
    SoftCopy* t1 = new SoftCopy(360, 24.0, 0, 18);      // 19 sayfalık kitap
    SoftCopy* t2 = new SoftCopy(360, 16.6, 10, 14);     // 5 sayfalık parça
    SoftCopy* t3 = new SoftCopy(360, 17.0, 4, 6);       // 3 sayfalık parça

    SoftCopy* r1 = new SoftCopy(320, 15.0, 0, 7);       // pow(2,3)= 8 sayfalık kitap
    SoftCopy* p1 = new SoftCopy(380, 11.0, 0, 7);       // pow(2,3)= 8 sayfalık kitap
    SoftCopy* q1 = new SoftCopy(390, 13.3, 0, 7);       // pow(2,3)= 8 sayfalık kitap
    SoftCopy* w1 = new SoftCopy(310, 60, 3, 9);         // 7 sayfalık kitap, boş kalacak

    SoftCopy* copy_s1 = NULL;
    SoftCopy* copy_s2 = NULL;
    SoftCopy* copy_r1 = NULL;

    /********************* Prepare softcopy page content ******************/
    string s_pages[20], t_pages[20];
    for (int i=0; i<20; i++) {
        string part1 = "PAGE CONTENT ";
        string part2 = ", in SOFT COPY 340";
        string part3 = ", in SOFT COPY 360";
        s_pages[i] = part1 + to_string(i) + part2;
        t_pages[i] = part1 + to_string(i) + part3;
    }

    string r_pages[8], p_pages[8], q_pages[8];
    for (int i=0; i<8; i++) {
        string part1 = "PAGE CONTENT ";
        string part2 = ", in SOFT COPY 320";
        string part3 = ", in SOFT COPY 380";
        string part4 = ", in SOFT COPY 390";
        r_pages[i] = part1 + to_string(i) + part2;
        p_pages[i] = part1 + to_string(i) + part3;
        q_pages[i] = part1 + to_string(i) + part4;
    }

    /************************** Upload Pages **************************/

    // Upload specific pages of s1
    s1->UploadPage(s_pages[0], 0);
    s1->UploadPage(s_pages[3], 3);
    s1->UploadPage(s_pages[17], 17);

    // Upload specific pages of s2
    s2->UploadPage(s_pages[10], 10);
    s2->UploadPage(s_pages[11], 11);
    s2->UploadPage(s_pages[12], 12);
    s2->UploadPage(s_pages[13], 13);
    s2->UploadPage(s_pages[14], 14);

    // Upload specific pages of t1
    t1->UploadPage(t_pages[0], 0);
    t1->UploadPage(t_pages[3], 3);
    t1->UploadPage(t_pages[17], 17);

    // Upload specific pages of t2
    t2->UploadPage(t_pages[10], 10);
    t2->UploadPage(t_pages[11], 11);
    t2->UploadPage(t_pages[12], 12);
    t2->UploadPage(t_pages[13], 13);
    t2->UploadPage(t_pages[14], 14);

    // Upload specific pages of t3
    t3->UploadPage(t_pages[4], 4);
    t3->UploadPage(t_pages[5], 5);
    t3->UploadPage(t_pages[6], 6);

    // Upload all pages of r1, build full tree
    for (int i=0; i<8; i++) {
        r1->UploadPage(r_pages[i], i);
        p1->UploadPage(p_pages[i], i);
        q1->UploadPage(q_pages[i], i);
    }

    copy_s1 = new SoftCopy(*s1);
    copy_s2 = new SoftCopy(*s2);
    copy_r1 = new SoftCopy(*r1);

    /************************** Assignment Tests **************************/
    *t1 = *t2;
    *t3 = *p1;
    *q1 = *w1;

    letscheck << *s1 << *s2 << *r1 << *t1 << *t2 << *t3 << *p1 << *q1 << *w1 << *copy_s1 << *copy_s2 << *copy_r1 << endl;

    delete s1;  s1 = NULL;
    delete s2;  s2 = NULL;
    delete r1;  r1 = NULL;
    delete t1;  t1 = NULL;
    delete t2;  t2 = NULL;
    delete t3;  t3 = NULL;
    delete p1;  p1 = NULL;
    delete q1;  q1 = NULL;
    delete w1;  w1 = NULL;
    delete copy_s1; copy_s1 = NULL;
    delete copy_s2; copy_s2 = NULL;
    delete copy_r1; copy_r1 = NULL;
    return letscheck;
}

stringstream tg4() {
    stringstream letscheck;

    /************************ Construct the books ************************/

    // Create SoftCopies
    SoftCopy* s1 = new SoftCopy(240, 12.0, 0, 18);      // 19 sayfalık kitap
    SoftCopy* s2 = new SoftCopy(240, 8.6, 10, 14);      // 5 sayfalık parça
    SoftCopy* s3 = new SoftCopy(240, 17.0, 4, 6);       // 3 sayfalık parça

    SoftCopy* r1 = new SoftCopy(220, 15.0, 0, 7);       // pow(2,3)= 8 sayfalık kitap

    SoftCopy* t1 = new SoftCopy(230, 16.5, 0, 15);      // pow(2,4) = 16 sayfalık kitap
    SoftCopy* t2 = new SoftCopy(230, 2, 10, 11);        // 2 sayfalık exact branch

    SoftCopy* w1 = new SoftCopy(250, 45.8, 0, 1025);    // Large book

    /********************* Prepare softcopy page content ******************/
    string s_pages[20];
    for (int i=0; i<20; i++) {
        string part1 = "PAGE CONTENT ";
        string part2 = ", in SOFT COPY 240";
        s_pages[i] = part1 + to_string(i) + part2;
    }

    string r_pages[8];
    for (int i=0; i<8; i++) {
        string part1 = "PAGE CONTENT ";
        string part2 = ", in SOFT COPY 220";
        r_pages[i] = part1 + to_string(i) + part2;
    }

    string t_pages[16];
    for (int i=0; i<16; i++) {
        string part1 = "PAGE CONTENT ";
        string part2 = ", in SOFT COPY 230";
        t_pages[i] = part1 + to_string(i) + part2;
    }

    string w_pages[8];
    int w_page_ids[8] = {825, 417, 100, 9, 310, 781, 615, 986};
    for (int i=0; i<8; i++) {
        string part1 = "PAGE CONTENT ";
        string part2 = ", in SOFT COPY 250";
        w_pages[i] = part1 + to_string(w_page_ids[i]) + part2;
    }

    /****************************** Upload Pages ****************************/
    // Upload all pages of r1, build full tree
    for (int i=0; i<8; i++)
        r1->UploadPage(r_pages[i], i);

    // Upload specific pages of s1
    s1->UploadPage(s_pages[0], 0);
    s1->UploadPage(s_pages[3], 3);
    s1->UploadPage(s_pages[17], 17);

    // Upload specific pages of s2
    s2->UploadPage(s_pages[10], 10);
    s2->UploadPage(s_pages[11], 11);
    s2->UploadPage(s_pages[12], 12);
    s2->UploadPage(s_pages[13], 13);
    s2->UploadPage(s_pages[14], 14);

    // Upload specific pages of s3
    s3->UploadPage(s_pages[4], 4);
    s3->UploadPage(s_pages[5], 5);
    s3->UploadPage(s_pages[6], 6);

    // Upload specific pages of t1
    t1->UploadPage(t_pages[1], 1);

    // Upload specific pages of t2
    t2->UploadPage(t_pages[10], 10);
    t2->UploadPage(t_pages[11], 11);

    // Upload specific pages of w1
    for (int i=0; i<8; i++)
        w1->UploadPage(w_pages[i], w_page_ids[i]);

    /****************************** Display Pages ****************************/
    string output = r1->Display(0, 7);
    letscheck << output << endl;
    output = s1->Display(0, 5);
    letscheck << output << endl;
    output = s2->Display(11, 12);
    letscheck << output << endl;
    output = t1->Display(7, 12);
    letscheck << output << endl;
    output = w1->Display(99, 765);
    letscheck << output << endl;
    letscheck << *r1 << *s1 << *s2  << *s3 << *t1 << *t2 << *w1 << endl;
    delete r1;  r1 = NULL;
    delete s1;  s1 = NULL;
    delete s2;  s2 = NULL;
    delete s3;  s3 = NULL;
    delete t1;  t1 = NULL;
    delete t2;  t2 = NULL;
    delete w1;  w1 = NULL;

    return letscheck;
}

stringstream tg5() {
    stringstream letscheck;
    /************************ Construct the books ************************/

    // Create SoftCopies
    SoftCopy* s1 = new SoftCopy(540, 12.0, 0, 18);      // 19 sayfalık kitap
    SoftCopy* s2 = new SoftCopy(540, 8.6, 10, 14);      // 5 sayfalık parça
    SoftCopy* s3 = new SoftCopy(540, 17.0, 4, 6);       // 3 sayfalık parça

    SoftCopy* r1 = new SoftCopy(520, 15.0, 0, 7);       // pow(2,3)= 8 sayfalık kitap
    SoftCopy* r2 = new SoftCopy(520, 10.0, 4, 4);

    SoftCopy* t1 = new SoftCopy(530, 16.5, 0, 15);      // pow(2,4) = 16 sayfalık kitap
    SoftCopy* t2 = new SoftCopy(530, 2, 10, 11);        // 2 sayfalık exact branch

    SoftCopy* w1 = new SoftCopy(550, 45.8, 0, 1025);    // Large book
    SoftCopy* w2 = new SoftCopy(550, 9.1, 49, 399);

    SoftCopy* k1 = new SoftCopy(590, 21.0, 8, 23);
    SoftCopy* k2 = new SoftCopy(590, 7.5, 18, 20);

    /********************* Prepare softcopy page content ******************/
    string s_pages[20];
    for (int i=0; i<20; i++) {
        string part1 = "PAGE CONTENT ";
        string part2 = ", in SOFT COPY 540";
        s_pages[i] = part1 + to_string(i) + part2;
    }

    string r_pages[8];
    for (int i=0; i<8; i++) {
        string part1 = "PAGE CONTENT ";
        string part2 = ", in SOFT COPY 520";
        r_pages[i] = part1 + to_string(i) + part2;
    }

    string t_pages[16];
    for (int i=0; i<16; i++) {
        string part1 = "PAGE CONTENT ";
        string part2 = ", in SOFT COPY 530";
        t_pages[i] = part1 + to_string(i) + part2;
    }

    string w_pages[10];
    int w_page_ids[10] = {825, 417, 100, 9, 310, 781, 615, 986, 199, 299};
    for (int i=0; i<10; i++) {
        string part1 = "PAGE CONTENT ";
        string part2 = ", in SOFT COPY 550";
        w_pages[i] = part1 + to_string(w_page_ids[i]) + part2;
    }

    string k_pages[24];
    for (int i=0; i<24; i++) {
        string part1 = "PAGE CONTENT ";
        string part2 = ", in SOFT COPY 590";
        k_pages[i] = part1 + to_string(i) + part2;
    }

    /****************************** Upload Pages ****************************/
    // Upload only one page into r2,
    r2->UploadPage(r_pages[4], 4);

    // Upload specific pages of s1
    s1->UploadPage(s_pages[0], 0);
    s1->UploadPage(s_pages[3], 3);
    s1->UploadPage(s_pages[17], 17);

    // Upload specific pages of s2
    s2->UploadPage(s_pages[10], 10);
    s2->UploadPage(s_pages[11], 11);
    s2->UploadPage(s_pages[12], 12);
    s2->UploadPage(s_pages[13], 13);
    s2->UploadPage(s_pages[14], 14);

    // Upload specific pages of s3
    s3->UploadPage(s_pages[4], 4);
    s3->UploadPage(s_pages[5], 5);
    s3->UploadPage(s_pages[6], 6);

    // Upload specific pages of t1
    t1->UploadPage(t_pages[1], 1);

    // Upload specific pages of t2
    t2->UploadPage(t_pages[10], 10);
    t2->UploadPage(t_pages[11], 11);

    // Upload specific pages of w1
    for (int i=0; i<8; i++)
        w1->UploadPage(w_pages[i], w_page_ids[i]);

    // Upload specific pages of w2
    w2->UploadPage(w_pages[8], w_page_ids[8]);
    w2->UploadPage(w_pages[9], w_page_ids[9]);

    // Upload specific pages of k1
    for (int i=8; i<24; i++) {
        if (i==19)
            continue;
        k1->UploadPage(k_pages[i], i);
    }
    k2->UploadPage(k_pages[19], 19);

    /************************ Summation Tests ***********************/

    SoftCopy& t12 = *t1 + *t2;
    SoftCopy& r12 = *r1 + *r2;
    SoftCopy& k12 = *k1 + *k2;
    SoftCopy& s12 = *s1 + *s2;
    SoftCopy& s123 = s12 + *s3;
    SoftCopy& w12 = *w1 + *w2;

    letscheck << *s1 << *s2 << *s3 << *r1 << *r2 << *t1 << *t2 << *w1 << *w2 << *k1 << *k2 << t12 << r12 << k12 << w12 << s12 << s123 << endl;

    /************************ Delete the softcopies ***********************/
    delete s1;  s1 = NULL;
    delete s2;  s2 = NULL;
    delete s3;  s3 = NULL;
    delete r1;  r1 = NULL;
    delete r2;  r2 = NULL;
    delete t1;  t1 = NULL;
    delete t2;  t2 = NULL;
    delete w1;  w1 = NULL;
    delete w2;  w2 = NULL;
    delete k1;  k1 = NULL;
    delete k2;  k2 = NULL;
    delete &t12;
    delete &r12;
    delete &k12;
    delete &w12;
    delete &s12;
    delete &s123;
    return  letscheck;
}


int main(){
    std::map<std::string, std::function<stringstream()>> functions;

    functions["1"] = tg1;
    functions["2"] = tg2;
    functions["3"] = tg3;
    functions["4"] = tg4;
    functions["5"] = tg5;

    for(int i = 1; i < 6; i++){
        std::ifstream t("outputs/"+ to_string(i) + ".txt");
        std::stringstream buffer;
        buffer << t.rdbuf();
        int res = buffer.str().compare(functions[to_string(i)]().str());
        if(!res){
            cout << "success on TestGroup" << to_string(i) << endl;
        } else {
            cout << "error on TestGroup" << to_string(i) << endl;
            cout << "\tyour output is written to outputs/e" + to_string(i) +".txt file. You can compare it via diff etc." << endl;

            ofstream err;
            err.open ("outputs/e" + to_string(i)+".txt");
            err << functions[to_string(i)]().str();
            err.close();

        }
    }

    return 0;
}

ostream &operator<<(ostream & os, const SoftCopy & sc) {
    for(int i = sc.startPage; i <= sc.endPage; i++ ){
        if(!sc.Display(i,i).empty())
            os << sc.Display(i,i) << endl;
    }
    return os;
}