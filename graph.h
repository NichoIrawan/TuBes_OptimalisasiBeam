#ifndef HALTE_GRAPH_H_INCLUDED
#define HALTE_GRAPH_H_INCLUDED
#include <iostream>
using namespace std;

//Graph untuk halte & jalan
struct jalan;
struct halteVertex;

typedef halteVertex* adrHalteVertex;
typedef jalan* adrJalan;

struct halteVertex
{
    string halteID;
    adrHalteVertex nextHalte;
    adrJalan firstEdge;
};

struct jalan
{
    string tujuanHalteID;
    int jarakHalte;
    adrJalan nextEdge;
};

struct HalteGraph
{
    adrHalteVertex firstHalte;
};

//Beam
typedef struct beam* adrBeam;

struct beam
{
    string idBeam;
    //halteVertex[10] historyJalan; // kalo gaboleh stack integer aja
    halteVertex location;
    adrBeam nextBeam;
};

struct beamList
{
    adrBeam firstBeam;
};

//Halte & Jalan
void createHalteVertex(string halteID, halteVertex* &v);
void createJalan(string tujuanHalteID, int jarakHalte);
void initHalteGraph(HalteGraph &G);
void addhalteVertex(HalteGraph &G, string halteID);
void addJalan(HalteGraph &G, string asalHalteID, string tujuanHalteID, int jarakHalte);
void buildHalteGraph(HalteGraph &G);
void printHalteGraph(HalteGraph G);

int hitungTotalJarak(HalteGraph G, beamList L, string idBeam);
int jumlahBeam(HalteGraph G, beamList L, string halteID);
void findRuteTerpendek(HalteGraph G, string startHalteID, string endHalteID);

//Beam
void createBeam (string idBeam, halteVertex location, beam &b);
void initBeamList (beamList L);
void insertBeam (beamList L, HalteGraph G, string idBeam, halteVertex location);
void beamJalan (beamList L, HalteGraph G);
void beamReacharge (beamList L, string idBeam);
#endif



