#ifndef _TARTNEULANDPLAPARA_H_
#define _TARTNEULANDPLAPARA_H_

#include "TArtTacquilaMap.hh"

class TArtSAMURAIParameters;

class TArtTacquilaPara : public TObject
{
  friend class TArtSAMURAIParameters;
public:
  TArtTacquilaPara()
    : TObject(), fID(0), fDetName("") {} 
  ~TArtTacquilaPara(){}

  void SetID(Int_t val){fID = val;}
  void SetDetectorName(const TString& val){fDetName = val;}
  Int_t GetID() const {return fID;}
  const TString& GetDetectorName() const {return fDetName;}

  void SetTac2Ns(Double_t val){fTac2Ns = val;} 
  Double_t GetTac2Ns() const {return fTac2Ns;} 

  const TArtTacquilaMap& GetMap() const {return fMap;}

private:
  Int_t     fID;
  TString   fDetName;

  Double_t  fTac2Ns;

  void SetMap(Int_t sam, Int_t gtb, Int_t mod, Int_t ch){
    fMap.SetMap(sam,gtb,mod,ch);
    //    std::cout << "0 is mapped to " << fMapU.GetMapInfo() << " " << fMapU.GetName() << std::endl;
  }

  TArtTacquilaMap fMap;

  ClassDef(TArtTacquilaPara,1);
};


class TArtNeuLANDPlaPara : public TObject
{
  friend class TArtSAMURAIParameters;

public:
  TArtNeuLANDPlaPara()
    : TObject(),
      fID(0), fDetName(""), fFpl(-1), 
      fDirection(""),
      fLayer(-1), fBarID(-1),
      tdiff_offset(-1), tsync_offset(-1), vscint(-1),
      ediff_offset(-1), esync_offset(-1), att(-1)
  {
    for(int i=0;i<2;i++){
      fQCal[i]=0; fQPed[i]=0; 
      fTDC0ns[i]=0; fTDC25ns[i]=0; fTDC0ns_t17[i]=0; fTDC25ns_t17[i]=0;
    }
  }
  ~TArtNeuLANDPlaPara(){}

  void SetID(Int_t val){fID = val;}
  void SetDetectorName(const TString& val){fDetName = val;}
  void SetFpl(Int_t val){fFpl = val;}
  void SetDirection(const TString& val){fDirection = val;}
  void SetLayer(Int_t val){fLayer = val;}
  void SetBarID(Int_t val){fBarID = val;}

  Int_t GetID() const {return fID;}
  const TString& GetDetectorName() const {return fDetName;}
  Int_t GetFpl() const {return fFpl;}
  const TString& GetDirection() const {return fDirection;}
  Int_t GetLayer() const {return fLayer;}
  Int_t GetBarID() const {return fBarID;}

  void SetQCal       (int i, Double_t val){fQCal[i] = val;} 
  void SetQPed       (int i, Double_t val){fQPed[i] = val;} 
  void SetTDC0ns     (int i, Double_t val){fTDC0ns[i] = val;} 
  void SetTDC25ns    (int i, Double_t val){fTDC25ns[i] = val;} 
  void SetTDC0ns_t17 (int i, Double_t val){fTDC0ns_t17[i] = val;} 
  void SetTDC25ns_t17(int i, Double_t val){fTDC25ns_t17[i] = val;} 

  Double_t GetQCal       (int i) const {return fQCal[i];} 
  Double_t GetQPed       (int i) const {return fQPed[i];} 
  Double_t GetTDC0ns     (int i) const {return fTDC0ns[i];} 
  Double_t GetTDC25ns    (int i) const {return fTDC25ns[i];} 
  Double_t GetTDC0ns_t17 (int i) const {return fTDC0ns_t17[i];} 
  Double_t GetTDC25ns_t17(int i) const {return fTDC25ns_t17[i];} 

  void SetTDiffOffset(Double_t val){tdiff_offset = val;} 
  void SetTSyncOffset(Double_t val){tsync_offset = val;} 
  void SetVScint     (Double_t val){vscint = val;} 
  void SetEDiffOffset(Double_t val){ediff_offset = val;} 
  void SetESyncOffset(Double_t val){esync_offset = val;} 
  void SetAtt        (Double_t val){att = val;} 

  Double_t GetTDiffOffset() const {return tdiff_offset;} 
  Double_t GetTSyncOffset() const {return tsync_offset;} 
  Double_t GetVScint     () const {return vscint;} 
  Double_t GetEDiffOffset() const {return ediff_offset;} 
  Double_t GetESyncOffset() const {return esync_offset;} 
  Double_t GetAtt        () const {return att;} 

  friend std::ostream& operator<<(std::ostream& out, const TArtNeuLANDPlaPara& p){
    out << "ID: "          << p.fID      << std::endl;
    out << "Det. Name: "   << p.fDetName << std::endl;
    out << "Focal Plane: " << p.fFpl     << std::endl;
    out << "Layer: "       << p.fLayer   << std::endl;
    out << "Bar ID: "      << p.fBarID   << std::endl;
    out << "Direction: "   << p.fDirection << std::endl;

    for(int i=0;i<2;i++){
      out << "Q"<<i<<"         Calib: " << p.fQCal[i]          << std::endl;
      out << "Q"<<i<<"      Pedestal: " << p.fQPed[i]          << std::endl;
      out << "T"<<i<<"  0ns      TDC: " << p.fTDC0ns[i]        << std::endl;
      out << "T"<<i<<" 25ns      TDC: " << p.fTDC25ns[i]       << std::endl;
      out << "T"<<i<<"  0ns ref. TDC: " << p.fTDC0ns_t17[i]    << std::endl;
      out << "T"<<i<<" 25ns ref. TDC: " << p.fTDC25ns_t17[i]   << std::endl;
    }

    out << "tdiff_offset: "   << p.tdiff_offset << std::endl;
    out << "tsync_offset: "   << p.tsync_offset << std::endl;
    out << "vscint: "         << p.vscint << std::endl;
    out << "ediff_offset: "   << p.ediff_offset << std::endl;
    out << "esync_offset: "   << p.esync_offset << std::endl;
    out << "att: "         << p.att << std::endl;

    out << "Map of 0: "    << p.fMap[0];
    out << "Map of 1: "    << p.fMap[1];
    out << std::endl;
    return out;
  }

  const TArtTacquilaMap& GetMap(int i) const {return fMap[i];}

private:
  Int_t     fID;
  TString   fDetName;
  Int_t     fFpl;
  TString   fDirection;
  Int_t     fLayer;
  Int_t     fBarID;

  Double_t  fQCal[2];
  Double_t  fQPed[2]; // qdc pedestal
  Double_t  fTDC0ns[2]; // tdc correspoinding to 0ns (calibration)
  Double_t  fTDC25ns[2]; // tdc correspoinding to 25ns:1clk (calibration)
  Double_t  fTDC0ns_t17[2]; // tdc correspoinding to 0ns of common stop (calibration)
  Double_t  fTDC25ns_t17[2]; // tdc correspoinding to 25ns:1clk of common stop (calibration)

  Double_t  tdiff_offset, tsync_offset, vscint;
  Double_t  ediff_offset, esync_offset, att;

  void SetMap(Int_t pmtid, Int_t sam, Int_t gtb, Int_t mod, Int_t ch){
    fMap[pmtid].SetMap(sam,gtb,mod,ch);
    //    std::cout << "0 is mapped to " << fMapU.GetMapInfo() << " " << fMapU.GetName() << std::endl;
  }

  TArtTacquilaMap fMap[2];

  ClassDef(TArtNeuLANDPlaPara,1);
};

#endif
