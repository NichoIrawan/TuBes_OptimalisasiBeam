#include "graph.h"

void createHalteVertex(string halteID, adrHalteVertex &v)
{
    v = new halteVertex)();
    v->halteID = halteID;
    v->nextHalte = nullptr;
    v->firstEdge = nullptr;
}

void createJalan(string tujuanHalteID, int jarakHalte, adrJalan &e)
{
    e = new jalan();
    e->tujuanHalteID = tujuanHalteID;
    e->jarakHalte = jarakHalte;
    e->nextEdge = nullptr;
}

void initHalteGraph(HalteGraph &G)
{
    G.firstHalte = nullptr;
}

void addHalteVertex(HalteGraph &G, string halteID)
{
    adrHalteVertex newHalte;
    createhalteVertex(halteID, newHalte);

    adrHalteVertex v = G.firstHalte;
    while (v->nextHalte != nullptr)
    {
        v = v->nextHalte;
    }
    v->nextHalte = newHalte;

}

void addJalan(HalteGraph &G, string asalHalteID, string tujuanHalteID, int jarakHalte)
{
    adrHalteVertex asal = G.firstHalte;
    while (asal != nullptr && asal->halteID != asalHalteID)
    {
        asal = asal->nextHalte;
    }

    if (asal != nullptr)
    {
        adrJalan newJalan;
        createJalan(tujuanHalteID, jarakHalte, newJalan);

        adrJalan tempJalan = asal->firstEdge;
        while (tempJalan->nextEdge != nullptr)
        {
            tempJalan = tempJalan->nextEdge;
        }
        tempJalan->nextEdge = newJalan;
    }
}

void buildHalteGraph(HalteGraph &G)
{
    string input;

    cout << "Masukkan nama halte ('0' untuk keluar): ";
    cin >> input;
    while (input != "0")
    {
        addHalteVertex(G, input);
        cout << "Masukkan nama halte ('0' untuk keluar): ";
        cin >> input;
    }
}

void printHalteGraph(HalteGraph G);

int hitungTotalJarak(HalteGraph G, beamList L, string idBeam)
{
    adrBeam b = L.firstBeam;
    while (b != nullptr && b->idBeam != idBeam)
    {
        b = b->nextBeam;
    }
    for (int i = 0; i < b->historyJalan)
}

void findRuteTerpendek(HalteGraph G, string startHalteID, string endHalteID);

void createBeam (string idBeam, halteVertex location, beam &b);

void initBeamList (beamList L);

void insertBeam (beamList L, HalteGraph G, string idBeam, halteVertex location);

void beamJalan (beamList L, HalteGraph G);

void beamReacharge (beamList L, string idBeam);
