#include "header.h"

int tikrinimas(){
    int input;
    cin >> input;
    if(cin.fail()){
        cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Ivedete ne int'a" << endl;
        return 0;
    }
    if(input>10){
        cout << "Pazymys negali but daugiau nei 10" << endl;
        return 0;
    }
    else return input;
}

void ivedimas(stud &temp){
    int input=0;
    while(input>=0){
        input = tikrinimas();
        if(input>0){
            temp.nd.push_back(input);
        }
    }
}

void generavimas(stud &temp, int kiek){
    srand ( time ( NULL ));
    for(int i=0; i<kiek; i++){
        temp.nd.push_back((int)(1 + ( double ) rand ()/ RAND_MAX * (11 - 1 )));
    }
}

double galVid(stud &temp){
    double vid;
    if(temp.nd.size()==0) vid=0;
    else{
        int suma=0;
        for(int a: temp.nd){
            suma+=a;
        }
        vid=(double)suma/temp.nd.size();
    }
    double gal;
    gal = 0.4 * vid + 0.6 * (double)temp.egz;
    return gal;
}

double galMed(stud &temp){
    double mediana;
    //jeigu namu darbu neivesta, tai mediana lygi 0
    if(temp.nd.size()==0) mediana=0;
    else{
        //surusiuoja nd vectoriu
        sort(temp.nd.begin(), temp.nd.end());
        if(temp.nd.size()%2!=0) mediana=temp.nd.at(temp.nd.size()/2);
        else mediana=(double)((temp.nd.at(temp.nd.size()/2)+temp.nd.at((temp.nd.size()/2-1))))/2;
    }
    double gal;
    gal = 0.4 * mediana + 0.6 * (double)temp.egz;
    return gal;
}

void tikrinimasBinarinio(int &sk){
    cin.clear();
    while(1){
        cin >> sk;
        if(cin.fail()){
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Ivedete ne int'a tikrinimas inarinio" << endl;
            sk = 2;
        }
        if(sk==1) break;
        else if(sk==0) break;
        else cout << "Turite ivesti 0 arba 1" << endl;
    }
}

void isvedimas(vector<stud> &studentai, int ar){
    //nustato, kruis studentas turi daugiausia raidziu savo varde ir pavardeje
    int didVard=0, didPav=0, temp;
    for(int i=0; i<studentai.size(); i++){
        temp = studentai[i].vardas.length();
        if(temp>didVard) didVard=temp;

        temp = studentai[i].pavarde.length();
        if(temp>didPav) didPav=temp;
    }

    cout << std::left << std::setw(didVard+3) << "Vardas" << std::left << std::setw(didPav+3) << "Pavarde";
    if(ar) cout << "Galutinis (Vid.)" << endl;
    else cout << "Galutinis (Med.)" << endl;
    for(int i=0; i<didVard+didPav+23; i++){
        cout << "-";
    }
    cout << endl;
    //rusiavimas pagal vardus
    //i string vectoriu v idedu visus studentu vardus
    vector<string> v;
    for(int i=0; i<studentai.size(); i++){
        v.push_back(studentai[i].vardas);
    }
    //surusiuoja abeceles tvarka
    sort(v.begin(),v.end());

    for(int i=0; i<studentai.size(); i++){
        for(int j=0; j<studentai.size(); j++){
            if(v.at(i)==studentai[j].vardas) cout << std::left << std::setw(didVard+3) << studentai[j].vardas << std::left << std::setw(didPav+3) << studentai[j].pavarde << std::left << std::setw(3) << std::fixed << std::setprecision(2) << studentai[j].galutinis << endl;
        }
    }
}

void tikrinimasDuom(int &sk){
    cin.clear();
    while(1){
        cin >> sk;
        if(cin.fail()){
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Ivedete ne int'a tikrinimas inarinio" << endl;
            sk = 3;
        }
        if(sk==1) break;
        else if(sk==0) break;
        else if(sk==2) break;
        else cout << "Turite ivesti 0 , 1 arba 2" << endl;
    }
}

void generavimasFailo(int kiekIrasu){
    srand ( time ( NULL ));
    std::ofstream fout ("generatedfile.txt");
    for(int i=0; i<kiekIrasu; i++){
        fout << "Vardas" << i+1 << " " << "Pavarde" << i+1 << " ";
        for(int j=0; j<11; j++){
            fout << (int)(1 + ( double ) rand ()/ RAND_MAX * (11 - 1 )) << " ";
        }
        fout << endl;
    }

}

//PIRMA STRATEGIJA
void rusiavimasStudentu(vector<stud> &studentai, vector<stud> &vargsiukai, vector<stud> &kietakai, int kiekIrasu){
    cout << "Programos metu naudojamas vector konteineris ir naudojama pirma strategija" << endl;
    vargsiukai.reserve(kiekIrasu);
    kietakai.reserve(kiekIrasu);
    for(int i=0; i<kiekIrasu; i++){
        if(studentai[i].galutinis>=5.0) kietakai.push_back(studentai[i]);
        else vargsiukai.push_back(studentai[i]);
    }
    vargsiukai.shrink_to_fit();
    kietakai.shrink_to_fit();
}

void rusiavimasStudentu(deque<stud> &studentai, deque<stud> &vargsiukai, deque<stud> &kietakai, int kiekIrasu){
    cout << "Programos metu naudojamas deque konteineris ir naudojama pirma strategija" << endl;
    for(int i=0; i<kiekIrasu; i++){
        if(studentai[i].galutinis>=5.0) kietakai.push_back(studentai[i]);
        else vargsiukai.push_back(studentai[i]);
    }
}

void rusiavimasStudentu(list<stud> &studentai, list<stud> &vargsiukai, list<stud> &kietakai, int kiekIrasu){
    cout << "Programos metu naudojamas list konteineris ir naudojama pirma strategija" << endl;
    auto it = studentai.begin();
    while(it!=studentai.end()){
        if(it->galutinis>=5.0) kietakai.push_back(*it);
        else vargsiukai.push_back(*it);
        it++;
    }
}

void surusiuotuIsvedimas(vector<stud> &vargsiukai, vector<stud> &kietakai){
    std::ofstream fout ("vargsiukai.txt");
    for(int i=0; i<vargsiukai.size(); i++){
        fout << vargsiukai[i].vardas << " " << vargsiukai[i].pavarde << " ";
        for(int j=0; j<vargsiukai[i].nd.size(); j++){
            fout << vargsiukai[i].nd[j] << " ";
        }
        fout << "Egz.: " << vargsiukai[i].egz << " Galutinis: " << vargsiukai[i].galutinis << endl;
    }

    std::ofstream ffout ("kietakai.txt");
    for(int i=0; i<kietakai.size(); i++){
        ffout << kietakai[i].vardas << " " << kietakai[i].pavarde << " ";
        for(int j=0; j<kietakai[i].nd.size(); j++){
            ffout << kietakai[i].nd[j] << " ";
        }
        ffout << "Egz.: " << kietakai[i].egz << " Galutinis: " << kietakai[i].galutinis << endl;
    }
}

void surusiuotuIsvedimas(deque<stud> &vargsiukai, deque<stud> &kietakai){
    std::ofstream fout ("vargsiukai.txt");
    for(int i=0; i<vargsiukai.size(); i++){
        fout << vargsiukai[i].vardas << " " << vargsiukai[i].pavarde << " ";
        for(int j=0; j<vargsiukai[i].nd.size(); j++){
            fout << vargsiukai[i].nd[j] << " ";
        }
        fout << "Egz.: " << vargsiukai[i].egz << " Galutinis: " << vargsiukai[i].galutinis << endl;
    }

    std::ofstream ffout ("kietakai.txt");
    for(int i=0; i<kietakai.size(); i++){
        ffout << kietakai[i].vardas << " " << kietakai[i].pavarde << " ";
        for(int j=0; j<kietakai[i].nd.size(); j++){
            ffout << kietakai[i].nd[j] << " ";
        }
        ffout << "Egz.: " << kietakai[i].egz << " Galutinis: " << kietakai[i].galutinis << endl;
    }
}

void surusiuotuIsvedimas(list<stud> &vargsiukai, list<stud> &kietakai){
    std::ofstream fout ("vargsiukai.txt");
    auto it = vargsiukai.begin();
     while(it!=vargsiukai.end()){
        fout << it->vardas << " " << it->pavarde << " ";
        for(int j=0; j<it->nd.size(); j++){
            fout << it->nd[j] << " ";
        }
        fout << "Egz.: " << it->egz << " Galutinis: " << it->galutinis << endl;
        it++;
    }

    std::ofstream ffout ("kietakai.txt");
    it = kietakai.begin();
     while(it!=kietakai.end()){
        ffout << it->vardas << " " << it->pavarde << " ";
        for(int j=0; j<it->nd.size(); j++){
            ffout << it->nd[j] << " ";
        }
        ffout << "Egz.: " << it->egz << " Galutinis: " << it->galutinis << endl;
        it++;
    }

}

//ANTRA STRATEGIJA
void rusiavimasStudentu(vector<stud> &studentai, vector<stud> &vargsiukai, int kiekIrasu){
    cout << "Programos metu naudojamas vector konteineris ir naudojama antra strategija" << endl;
    for(int i=0; i<studentai.size(); i++){
        if(studentai[i].galutinis < 5.0){
            vargsiukai.push_back(studentai[i]);
            studentai.erase(studentai.begin()+i);
            i--;
        }
    }
}

void rusiavimasStudentu(deque<stud> &studentai, deque<stud> &vargsiukai, int kiekIrasu){
    cout << "Programos metu naudojamas deque konteineris ir naudojama antra strategija" << endl;
    for(int i=0; i<studentai.size(); i++){
        if(studentai[i].galutinis < 5.0){
            vargsiukai.push_back(studentai[i]);
            studentai.erase(studentai.begin()+i);
            i--;
        }
    }
}

void rusiavimasStudentu(list<stud> &studentai, list<stud> &vargsiukai, int kiekIrasu){
    cout << "Programos metu naudojamas list konteineris ir naudojama antra strategija " << endl;
    auto it = studentai.begin();
    while(it!=studentai.end()){
        if(it->galutinis<5.0){
            vargsiukai.push_back(*it);
            it = studentai.erase(it);
        }
        else it++;
    }
}

void surusiuotuIsvedimas(vector<stud> &vargsiukai, vector<stud> &studentai, int f){
    std::ofstream fout ("vargsiukai.txt");
    for(int i=0; i<vargsiukai.size(); i++){
        fout << vargsiukai[i].vardas << " " << vargsiukai[i].pavarde << " ";
        for(int j=0; j<vargsiukai[i].nd.size(); j++){
            fout << vargsiukai[i].nd[j] << " ";
        }
        fout << "Egz.: " << vargsiukai[i].egz << " Galutinis: " << vargsiukai[i].galutinis << endl;
    }

    std::ofstream ffout ("kietakai.txt");
    for(int i=0; i<studentai.size(); i++){
        ffout << studentai[i].vardas << " " << studentai[i].pavarde << " ";
        for(int j=0; j<studentai[i].nd.size(); j++){
            ffout << studentai[i].nd[j] << " ";
        }
        ffout << "Egz.: " << studentai[i].egz << " Galutinis: " << studentai[i].galutinis << endl;
    }
}

void surusiuotuIsvedimas(deque<stud> &vargsiukai, deque<stud> &studentai, int f){
    std::ofstream fout ("vargsiukai.txt");
    for(int i=0; i<vargsiukai.size(); i++){
        fout << vargsiukai[i].vardas << " " << vargsiukai[i].pavarde << " ";
        for(int j=0; j<vargsiukai[i].nd.size(); j++){
            fout << vargsiukai[i].nd[j] << " ";
        }
        fout << "Egz.: " << vargsiukai[i].egz << " Galutinis: " << vargsiukai[i].galutinis << endl;
    }

    std::ofstream ffout ("kietakai.txt");
    for(int i=0; i<studentai.size(); i++){
        ffout << studentai[i].vardas << " " <<studentai[i].pavarde << " ";
        for(int j=0; j<studentai[i].nd.size(); j++){
            ffout << studentai[i].nd[j] << " ";
        }
        ffout << "Egz.: " <<studentai[i].egz << " Galutinis: " << studentai[i].galutinis << endl;
    }
}

void surusiuotuIsvedimas(list<stud> &vargsiukai, list<stud> &studentai, int f){
    std::ofstream fout ("vargsiukai.txt");
    auto it = vargsiukai.begin();
     while(it!=vargsiukai.end()){
        fout << it->vardas << " " << it->pavarde << " ";
        for(int j=0; j<it->nd.size(); j++){
            fout << it->nd[j] << " ";
        }
        fout << "Egz.: " << it->egz << " Galutinis: " << it->galutinis << endl;
        it++;
    }

    std::ofstream ffout ("kietakai.txt");
    it = studentai.begin();
     while(it!=studentai.end()){
        ffout << it->vardas << " " << it->pavarde << " ";
        for(int j=0; j<it->nd.size(); j++){
            ffout << it->nd[j] << " ";
        }
        ffout << "Egz.: " << it->egz << " Galutinis: " << it->galutinis << endl;
        it++;
    }

}

//PARTITION ALGORITMO NAUDOJIMAS
bool isVargsiukas (const stud& laikinas) { return laikinas.galutinis < 5.0; }

void rusiavimasSuPartition(vector<stud> &studentai){
    auto it = std::partition(studentai.begin(), studentai.end(), isVargsiukas);

    //ISVEDIMAS I FAILUS
    std::ofstream fout ("vargsiukai.txt");
    for (auto i=studentai.begin(); i!=it; i++){
        fout << i->vardas << " " << i->pavarde << " ";
        for(int j=0; j<i->nd.size(); j++){
            fout << i->nd[j] << " ";
        }
        fout << "Egz.: " << i->egz << " Galutinis: " << i->galutinis << endl;
    }

    std::ofstream ffout ("kietakai.txt");
    for (auto i=it; i!=studentai.end(); i++){
        ffout << i->vardas << " " << i->pavarde << " ";
        for(int j=0; j<i->nd.size(); j++){
            ffout << i->nd[j] << " ";
        }
        ffout << "Egz.: " << i->egz << " Galutinis: " << i->galutinis << endl;
    }
}

//PAPILDOMA UZDUOTIS
void raskMinkstus(vector<stud> &studentai, vector<stud> &vargsiukai){
    auto start = std::chrono::system_clock::now();

    for(int i=0; i<studentai.size(); i++){
        if(studentai[i].galutinis < 5.0){
            vargsiukai.push_back(studentai[i]);
            studentai.erase(studentai.begin()+i);
            i--;
        }
    }

    auto end = std::chrono::system_clock::now();
    auto elapsedMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    auto elapsedS = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    cout << "Funkcijos raskMinkstus trukme: " << elapsedMS.count() << "ms arba apytiksliai " << elapsedS.count() << "s" << endl;
    cout << endl;
}

void iterpkKietus(vector<stud> &studentai, vector<stud> &vargsiukai){
    auto start = std::chrono::system_clock::now();

    vector<stud>::size_type i = 0;
    vector<stud>::size_type kiek = 0; //parodo, kiek bus kietaku
    while(i != studentai.size()){
        if (studentai[i].galutinis < 5.0){
            vargsiukai.push_back(studentai[i]);
        }
        else{
            studentai[kiek] = studentai[i];
            kiek++;
        }
        i++;
    }
    studentai.resize(kiek);
    studentai.shrink_to_fit();

    auto end = std::chrono::system_clock::now();
    auto elapsedMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    auto elapsedS = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    cout << "Funkcijos iterpkKietus naudojant vector konteineri trukme: " << elapsedMS.count() << "ms arba apytiksliai " << elapsedS.count() << "s" << endl;
    cout << endl;
}

void iterpkKietus(deque<stud> &studentai, deque<stud> &vargsiukai){
    auto start = std::chrono::system_clock::now();
    vector<stud>::size_type i = 0;
    vector<stud>::size_type galas = studentai.size();
    vector<stud>::size_type kiek = 0; //parodo, kiek bus kietaku
    while(i != galas){
        if (studentai[i].galutinis < 5.0){
            vargsiukai.push_back(studentai[i]);
        }
        else{
            studentai.push_front(studentai[i]);
            kiek++;
        }
        i++;
    }
    studentai.resize(kiek);
    studentai.shrink_to_fit();

    auto end = std::chrono::system_clock::now();
    auto elapsedMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    auto elapsedS = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    cout << "Funkcijos iterpkKietus naudojant deque konteineri trukme: " << elapsedMS.count() << "ms arba apytiksliai " << elapsedS.count() << "s" << endl;
    cout << endl;
}
