//
//  并查集.cpp
//  C++Learning
//
//  Created by yourui on 2020/3/20.
//  Copyright © 2020 yourui. All rights reserved.
//
#include <vector>
using namespace std;

unordered_map<string ,string> fa;
string find(string str){
    if(fa[str] == str){
        return str;
    }else{
        return find(fa[str]);
    }
}
void merge(string a, string b){
    string x = find(a);
    string y = find(b);
    if(x < y){
        fa[b] = a;
    }else{
        fa[a] = b;
    }
}
vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
    vector<string> res;
    unordered_map<string, int> CMap;
    unordered_map<string, int>::iterator it;
    for(int i = 0; i < synonyms.size();i++){
        int b = synonyms[i].find(',');
        int c = (int)synonyms[i].length()-2;
        string str1 = synonyms[i].substr(1, b-1);
        string str2 = synonyms[i].substr(b+1, c-b);
        fa[str1] = str1;
        fa[str2] = str2;
        merge(str1, str2);
    }

    for(int i = 0; i < names.size(); i++){
        int a = names[i].find('(');
        string name = names[i].substr(0, a);
        int count = stoi(names[i].substr(a+1));
        CMap[fa[name]] += count;
    }

    for(it = CMap.begin(); it != CMap.end(); it++){
        string temp = it->first + "(";
        temp += to_string(it->second) + ")";
        res.push_back(temp);
    }
    return res;
}
int main()
{
    vector<string>  names = {"Fcclu(70)","Ommjh(63)","Dnsay(60)","Qbmk(45)","Unsb(26)","Gauuk(75)","Wzyyim(34)","Bnea(55)","Kri(71)","Qnaakk(76)","Gnplfi(68)","Hfp(97)","Qoi(70)","Ijveol(46)","Iidh(64)","Qiy(26)","Mcnef(59)","Hvueqc(91)","Obcbxb(54)","Dhe(79)","Jfq(26)","Uwjsu(41)","Wfmspz(39)","Ebov(96)","Ofl(72)","Uvkdpn(71)","Avcp(41)","Msyr(9)","Pgfpma(95)","Vbp(89)","Koaak(53)","Qyqifg(85)","Dwayf(97)","Oltadg(95)","Mwwvj(70)","Uxf(74)","Qvjp(6)","Grqrg(81)","Naf(3)","Xjjol(62)","Ibink(32)","Qxabri(41)","Ucqh(51)","Mtz(72)","Aeax(82)","Kxutz(5)","Qweye(15)","Ard(82)","Chycnm(4)","Hcvcgc(97)","Knpuq(61)","Yeekgc(11)","Ntfr(70)","Lucf(62)","Uhsg(23)","Csh(39)","Txixz(87)","Kgabb(80)","Weusps(79)","Nuq(61)","Drzsnw(87)","Xxmsn(98)","Onnev(77)","Owh(64)","Fpaf(46)","Hvia(6)","Kufa(95)","Chhmx(66)","Avmzs(39)","Okwuq(96)","Hrschk(30)","Ffwni(67)","Wpagta(25)","Npilye(14)","Axwtno(57)","Qxkjt(31)","Dwifi(51)","Kasgmw(95)","Vgxj(11)","Nsgbth(26)","Nzaz(51)","Owk(87)","Yjc(94)","Hljt(21)","Jvqg(47)","Alrksy(69)","Tlv(95)","Acohsf(86)","Qejo(60)","Gbclj(20)","Nekuam(17)","Meutux(64)","Tuvzkd(85)","Fvkhz(98)","Rngl(12)","Gbkq(77)","Uzgx(65)","Ghc(15)","Qsc(48)","Siv(47)"};
    vector<string> synonyms = {"(Gnplfi,Qxabri)","(Uzgx,Siv)","(Bnea,Lucf)","(Qnaakk,Msyr)","(Grqrg,Gbclj)","(Uhsg,Qejo)","(Csh,Wpagta)","(Xjjol,Lucf)","(Qoi,Obcbxb)","(Npilye,Vgxj)","(Aeax,Ghc)","(Txixz,Ffwni)","(Qweye,Qsc)","(Kri,Tuvzkd)","(Ommjh,Vbp)","(Pgfpma,Xxmsn)","(Uhsg,Csh)","(Qvjp,Kxutz)","(Qxkjt,Tlv)","(Wfmspz,Owk)","(Dwayf,Chycnm)","(Iidh,Qvjp)","(Dnsay,Rngl)","(Qweye,Tlv)","(Wzyyim,Kxutz)","(Hvueqc,Qejo)","(Tlv,Ghc)","(Hvia,Fvkhz)","(Msyr,Owk)","(Hrschk,Hljt)","(Owh,Gbclj)","(Dwifi,Uzgx)","(Iidh,Fpaf)","(Iidh,Meutux)","(Txixz,Ghc)","(Gbclj,Qsc)","(Kgabb,Tuvzkd)","(Uwjsu,Grqrg)","(Vbp,Dwayf)","(Xxmsn,Chhmx)","(Uxf,Uzgx)"}
    vector<string> res = trulyMostPopular(names, synonyms);
}
/*
//标答 ["Fcclu(70)","Dnsay(72)","Qbmk(45)","Unsb(26)","Gauuk(75)","Gnplfi(109)","Hfp(97)","Obcbxb(124)","Ijveol(46)","Fpaf(219)","Qiy(26)","Mcnef(59)","Dhe(79)","Jfq(26)","Ebov(96)","Ofl(72)","Uvkdpn(71)","Avcp(41)","Chycnm(253)","Koaak(53)","Qyqifg(85)","Oltadg(95)","Mwwvj(70)","Naf(3)","Ibink(32)","Ucqh(51)","Mtz(72)","Ard(82)","Hcvcgc(97)","Knpuq(61)","Yeekgc(11)","Ntfr(70)","Bnea(179)","Weusps(79)","Nuq(61)","Drzsnw(87)","Chhmx(259)","Onnev(77)","Kufa(95)","Avmzs(39)","Okwuq(96)","Hljt(51)","Npilye(25)","Axwtno(57)","Kasgmw(95)","Nsgbth(26)","Nzaz(51)","Msyr(211)","Yjc(94)","Jvqg(47)","Alrksy(69)","Aeax(646)","Acohsf(86)","Csh(238)","Nekuam(17)","Kgabb(236)","Fvkhz(104)","Gbkq(77)","Dwifi(237)"]
 
 */
