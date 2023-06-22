#pragma once
#ifndef roomcontrolXmlLib
#define roomcontrolXmlLib
#include <iostream>\n\t";
#include <fstream>\n\t";
#include <windows.h>\n\t";
#include "mortLib.h"




//Datatyper
void Knx_dt_Rb(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"RB60" << i << "_V\">\n\t";

        fOutput << "<type>\n\t";
        fOutput << "<BOOL />\n\t";
        fOutput << "</type>\n\t";

        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Bevegelse</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);

        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}


void Knx_dt_Hvac(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall, std::string& sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"RB60" << i << "_HVAC\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">HVAC signal</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
    }

    if (sFb == "1" && iAntall > 1)
    {
        fOutput << "<variable name=\"RB600_HVAC\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">HVAC signal samlet</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
    }

    fOutput.close();
    return;
}


void Knx_dt_Rt(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall, std::string& sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        //CT
        fOutput << "<variable name=\"RT60" << i << "_CT\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Rom temperatur</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";

        if (i > 1 && sFb != "1")
        {
            //SP
            fOutput << "<variable name=\"RT60" << i << "_SP\">\n\t";
            fOutput << "<type>\n\t";
            fOutput << "<REAL />\n\t";
            fOutput << "</type>\n\t";
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Temperatur SP</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            fOutput << "</variable>\n\t";
        }
    }
    if (sFb == "1" && iAntall > 1)
    {
        //600CT
        fOutput << "<variable name=\"RT600" << "_CT\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Temperatur SP</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
        //SP D
        fOutput << "<variable name=\"RT600_SP_D\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Temperatur SP</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
        //SP S
        fOutput << "<variable name=\"RT600_SP_S\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Temperatur SP standby</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
        //SP N
        fOutput << "<variable name=\"RT600_SP_N\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Temperatur SP nattsenk</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
        //SP F
        fOutput << "<variable name=\"RT600_SP_F\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Temperatur SP frostsikring</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";

        //SP CS
        fOutput << "<variable name=\"RT600_CS\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Aktivt temperatur SP</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
    }
    else
    {
        //SP D
        fOutput << "<variable name=\"RT601_SP_D\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Temperatur SP</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
        //SP S
        fOutput << "<variable name=\"RT601_SP_S\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Temperatur SP standby</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
        //SP N
        fOutput << "<variable name=\"RT601_SP_N\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Temperatur SP nattsenk</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
        //SP F
        fOutput << "<variable name=\"RT601_SP_F\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Temperatur SP frostsikring</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
        //SP CS
        fOutput << "<variable name=\"RT601_CS\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Aktivt temperatur SP</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
    }
    //OPM
    fOutput << "<variable name=\"OPM\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<INT />\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Rom modus</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";
    //OPM CV
    fOutput << "<variable name=\"OPM_CV\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<INT />\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Rom modus verdi</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    fOutput.close();
    return;
}

void Knx_dt_Ry(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall, std::string& sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);


    for (int i = 1; i <= iAntall; i++)
    {
        //CV
        fOutput << "<variable name=\"RY60" << i << "_CV\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Co2 Nivaa</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
    }
    if (sFb == "1" && iAntall > 1)
    {
        //600_CV
        fOutput << "<variable name=\"RY600_CV\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Co2 gjennomsnitt</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
        //SP
        fOutput << "<variable name=\"RY600_SP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Co2 SP</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
        //MAN
        fOutput << "<variable name=\"RY600_MAN\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Co2 Man mode</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
        //OP
        fOutput << "<variable name=\"RY600_OP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Co2 paadrag</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
    }
    else
    {
        //SP
        fOutput << "<variable name=\"RY601_SP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Co2 SP</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
        //MAN
        fOutput << "<variable name=\"RY601_MAN\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Co2 Man mode</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
        //OP
        fOutput << "<variable name=\"RY601_OP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Co2 paadrag</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
    }

    fOutput.close();
    return;
}

void Knx_dt_Lh_OP(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        //OP
        fOutput << "<variable name=\"LH60" << i << "_OP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Varmepaadrag</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
    }
    //Force
    fOutput << "<variable name=\"LH601_MAN\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<BOOL />\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Force LH</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    fOutput.close();
    return;
}

void Knx_dt_Lh_CMD(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall, bool& xLh)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"LH60" << i << "_CMD\">\n\t";

        fOutput << "<type>\n\t";
        fOutput << "<BOOL />\n\t";
        fOutput << "</type>\n\t";


        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LH60" << i << "_CMD</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);

        fOutput << "</variable>\n\t";
    }

    if (!xLh)
    {
        fOutput << "<variable name=\"LH601_MAN\">\n\t";

        fOutput << "<type>\n\t";
        fOutput << "<BOOL />\n\t";
        fOutput << "</type>\n\t";


        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Force LH</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);

        fOutput << "</variable>\n\t";
    }

    fOutput.close();
    return;
}

void Knx_dt_Lc_OP(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"LC60" << i << "_OP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LC60" << i << "_OP</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
    }

    fOutput << "<variable name=\"LC601_SP\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL />\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LC SP</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Force
    fOutput << "<variable name=\"LC601_MAN\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<BOOL />\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Force LC</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";


    fOutput.close();
    return;
}

void Knx_dt_Lc_CMD(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall, bool& xLc)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"LC60" << i << "_CMD\">\n\t";

        fOutput << "<type>\n\t";
        fOutput << "<BOOL />\n\t";
        fOutput << "</type>\n\t";

        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LC60" << i << "_CMD</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);

        fOutput << "</variable>\n\t";
    }

    if (!xLc)
    {
        fOutput << "<variable name=\"LC601_SP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LC SP</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";


        fOutput << "<variable name=\"LC601_MAN\">\n\t";

        fOutput << "<type>\n\t";
        fOutput << "<BOOL />\n\t";
        fOutput << "</type>\n\t";


        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Force LC</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);

        fOutput << "</variable>\n\t";
    }

    fOutput.close();
    return;
}

void Knx_dt_Sp(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<variable name=\"RT601_SP\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL />\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Temperatur SP feedback</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    fOutput.close();
    return;
}

void Knx_dt_Sp_Fb(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        //SP FB
        fOutput << "<variable name=\"RT60" << i << "_SP_FB\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Temperatur SP</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
        //SP CS
        fOutput << "<variable name=\"RT60" << i << "_SP_IN\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Temperatur SP lokalt panel</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";
    }

    fOutput.close();
    return;
}

void Knx_dt_Lu_V(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"LU60" << i << "_V\">\n\t";

        fOutput << "<type>\n\t";
        fOutput << "<BOOL />\n\t";
        fOutput << "</type>\n\t";

        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Befukter status</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);

        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_dt_Lu_Al(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"LU60" << i << "_AL\">\n\t";

        fOutput << "<type>\n\t";
        fOutput << "<BOOL />\n\t";
        fOutput << "</type>\n\t";

        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Befukter alarm/feil</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);

        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_dt_Lu_Cmd(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"LU60" << i << "_CMD\">\n\t";

        fOutput << "<type>\n\t";
        fOutput << "<BOOL />\n\t";
        fOutput << "</type>\n\t";

        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Befukter tillat start</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);

        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_dt_Opm_Out(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"OPM_00" << i << "\">\n\t";

        fOutput << "<type>\n\t";
        fOutput << "<BYTE />\n\t";
        fOutput << "</type>\n\t";

        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">OPM output</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);

        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_dt_Rh_Cv(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"RH60" << i << "\">\n\t";

        fOutput << "<type>\n\t";
        fOutput << "<REAL />\n\t";
        fOutput << "</type>\n\t";

        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Rom fuktighet</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);

        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}








/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Funksjonsblokk variabler
//Inputs
void Knx_Fb_In_Hvac(std::string& sPath, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name = \"RB60" << i << "_HVAC\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }

    fOutput.close();
    return;
}

void Knx_Fb_In_Rt(std::string& sPath, int& iAntall, std::string& sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name = \"RT60" << i << "_CT\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";

        if (i > 1 and sFb != "1")
        {
            fOutput << "<variable name = \"RT60" << i << "_SP\">\n\t";
            fOutput << "<type>\n\t";
            fOutput << "<REAL/>\n\t";
            fOutput << "</type>\n\t";
            fOutput << "</variable>\n\t";
        }
    }
    if (sFb == "1" && iAntall > 1)
    {
        fOutput << "<variable name = \"RT600_SP_D\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RT600_SP_S\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RT600_SP_N\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RT600_SP_F\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    else
    {
        fOutput << "<variable name = \"RT601_SP_D\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RT601_SP_S\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RT601_SP_N\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RT601_SP_F\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }

    fOutput << "<variable name = \"OPM\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<INT/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "</variable>\n\t";

    fOutput.close();
    return;
}

void Knx_Fb_In_Ry(std::string& sPath, int& iAntall, std::string& sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name = \"RY60" << i << "_CV\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    if (sFb == "1" && iAntall > 1)
    {
        fOutput << "<variable name = \"RY600_SP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY600_MAN\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    else
    {
        fOutput << "<variable name = \"RY601_SP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY601_MAN\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_Fb_In_Lh(std::string& sPath, int& iAntall, std::string& sFb, int iAntallT)
{
    std::ofstream fOutput(sPath, std::ios::app);

    if (sFb == "1" && iAntallT > 1)
    {
        fOutput << "<variable name = \"LH600_MAN\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    else
    {
        fOutput << "<variable name = \"LH601_MAN\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_Fb_In_Lc(std::string& sPath, int& iAntall, std::string& sFb, int iAntallT)
{
    std::ofstream fOutput(sPath, std::ios::app);

    if (sFb == "1" && iAntallT > 1)
    {
        fOutput << "<variable name = \"LC600_SP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LC600_MAN\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    else
    {
        fOutput << "<variable name = \"LC601_SP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LC601_MAN\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_Fb_In_Sp_In(std::string& sPath, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name = \"RT60" << i << "_SP_IN\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_Fb_In_Lu_V(std::string& sPath, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name = \"LU60" << i << "_V\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_Fb_In_Lu_Al(std::string& sPath, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name = \"LU60" << i << "_AL\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_Fb_In_Rh_Cv(std::string& sPath, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name = \"RH60" << i << "_CV\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}





//local vars //nytt     //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Knx_Fb_Local_Ry(std::string& sPath, int& iAntall, std::string& sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    if (sFb == "1" && iAntall > 1)
    {
        fOutput << "<variable name = \"RY600_PID_Man\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Co2 regulering</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY600_PID_ManVal\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY600_PID\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbSE_PID\" />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY600_PID_Kp\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"1\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID Luft rom. Forsterkning</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY600_PID_Ti\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"10\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID luft rom. I-tid</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY600_PID_Td\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID luft rom. D-tid</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY600_PID_Zero\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID luft rom. 0-punkt</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY600_PID_Max\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"2000\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID luft rom. Max verdi ppm</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY600_PID_fMan\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"100\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID varme rom. Manuelt kjoeling</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";
    }
    else
    {
        fOutput << "<variable name = \"RY601_PID_Man\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n" + Tabs(7);
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Co2 regulering</xhtml>\n" + Tabs(6);
        fOutput << "</documentation>\n" + Tabs(5);
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY601_PID_ManVal\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY601_PID\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbSE_PID\" />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY601_PID_Kp\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"1\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID Luft rom. Forsterkning</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY601_PID_Ti\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"10\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID luft rom. I-tid</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY601_PID_Td\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID luft rom. D-tid</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY601_PID_Zero\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID luft rom. 0-punkt</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY601_PID_Max\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"2000\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID luft rom. Max verdi ppm</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"RY601_PID_fMan\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"100\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID varme rom. Manuelt kjoeling</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";
    }

    fOutput.close();
    return;
}

void Knx_Fb_Local_Lh_Op(std::string& sPath, int& iAntall, std::string& sFb, int iAntallT)
{
    std::ofstream fOutput(sPath, std::ios::app);

    if (sFb == "1" && iAntallT > 1)
    {
        fOutput << "<variable name = \"LH600_PID\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbSE_PID\" />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID varme rom</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LH600_PID_Kp\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"1\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID varme rom. Forsterkning</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LH600_PID_Ti\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"10\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID varme rom. I-tid</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LH600_PID_Td\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID varme rom. D-tid</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LH600_PID_fMan\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"100\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID varme rom. Manuelt paadrag</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";
    }
    else
    {
        fOutput << "<variable name = \"LH601_PID\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbSE_PID\" />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID varme rom</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LH601_PID_Kp\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"1\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID varme rom. Forsterkning</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LH601_PID_Ti\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"10\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID varme rom. I-tid</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LH601_PID_Td\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID varme rom. D-tid</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LH601_PID_fMan\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"100\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID varme rom. Manuelt paadrag</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_Fb_Local_Lh_Cmd(std::string& sPath, int& iAntall, std::string& sFb, int iAntallT)
{
    std::ofstream fOutput(sPath, std::ios::app);

    if (sFb == "1" && iAntallT > 1)
    {
        fOutput << "<variable name = \"LH600_T\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbSE_Hyst\" />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">Termostat varme rom</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LH600_T_On\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"0.5\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LH600_T_Off\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"0.1\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "</variable>\n\t";
    }
    else
    {
        fOutput << "<variable name = \"LH601_T\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbSE_Hyst\" />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">Termostat varme rom</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LH601_T_On\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"0.5\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LH601_T_Off\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"0.1\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "</variable>\n\t";
    }

    fOutput.close();
    return;
}

void Knx_Fb_Local_Lc_Op(std::string& sPath, int& iAntall, std::string& sFb, int iAntallT)
{
    std::ofstream fOutput(sPath, std::ios::app);

    if (sFb == "1" && iAntallT > 1)
    {
        fOutput << "<variable name = \"LC600_PID\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbSE_PID\" />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID kjoeling rom</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LC600_PID_Kp\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"1\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID kjoeling rom. Forsterkning</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LC600_PID_Ti\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"10\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID kjoeling rom. I-tid</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LC600_PID_Td\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID kjoeling rom. D-tid</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LC600_PID_fMan\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"100\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID varme rom. Manuelt kjoeling</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";
    }
    else
    {
        fOutput << "<variable name = \"LC601_PID\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbSE_PID\" />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID kjoeling rom</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LC601_PID_Kp\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"1\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID kjoeling rom. Forsterkning</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LC601_PID_Ti\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"10\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID kjoeling rom. I-tid</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LC601_PID_Td\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID kjoeling rom. D-tid</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LC601_PID_fMan\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"100\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">PID varme rom. Manuelt kjoeling</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_Fb_Local_Lc_Cmd(std::string& sPath, int& iAntall, std::string& sFb, int iAntallT)
{
    std::ofstream fOutput(sPath, std::ios::app);

    if (sFb == "1" && iAntallT > 1)
    {
        fOutput << "<variable name = \"LC600_T\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbSE_Hyst\" />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">Termostat kjoeling rom</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LC600_T_On\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"0.5\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LC600_T_Off\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"0.1\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "</variable>\n\t";
    }
    else
    {
        fOutput << "<variable name = \"LC601_T\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbSE_Hyst\" />\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<documentation>\n\t";
        fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\">Termostat kjoeling rom</xhtml>\n\t";
        fOutput << "</documentation>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LC601_T_On\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"0.5\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable name = \"LC601_T_Off\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "<initialValue>\n\t\t";
        fOutput << "<simpleValue value = \"0.1\" />\n\t";
        fOutput << "</initialValue>\n\t\t";
        fOutput << "</variable>\n\t";
    }

    fOutput.close();
    return;
}




//outvars
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Knx_Fb_Out_Hvac(std::string& sPath)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<variable name = \"RB600_HVAC\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<BOOL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "</variable>\n\t";

    fOutput.close();
    return;
}

void Knx_Fb_Out_Rt(std::string& sPath, int& iAntall, std::string& sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<variable name = \"OPM_CV\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<INT/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "</variable>\n\t";

    if (iAntall > 1 && sFb != "1")
    {
        for (int i = 0; i < iAntall; i++)
        {
            fOutput << "<variable name = \"RT60" << i + 1 << "_CS\">\n\t";
            fOutput << "<type>\n\t";
            fOutput << "<REAL/>\n\t";
            fOutput << "</type>\n\t";
            fOutput << "</variable>\n\t";
        }
    }
    else if (iAntall > 1)
    {
        fOutput << "<variable name = \"RT600_CT\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable name = \"RT600_CS\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    else
    {
        fOutput << "<variable name = \"RT601_CS\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }

    fOutput.close();
    return;
}

void Knx_Fb_Out_Ry(std::string& sPath, int& iAntall, std::string& sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    if (iAntall > 1 && sFb != "1")
    {
        for (int i = 0; i < iAntall; i++)
        {
            fOutput << "<variable name = \"RY60" << i + 1 << "_OP\">\n\t";
            fOutput << "<type>\n\t";
            fOutput << "<REAL/>\n\t";
            fOutput << "</type>\n\t";
            fOutput << "</variable>\n\t";
        }
    }
    else if (iAntall > 1)
    {
        fOutput << "<variable name = \"RY600_CV\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable name = \"RY600_OP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    else
    {
        fOutput << "<variable name = \"RY601_OP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }

    fOutput.close();
    return;
}

void Knx_Fb_Out_Lh_Op(std::string& sPath, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name = \"LH60" << i << "_OP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_Fb_Out_Lh_Cmd(std::string& sPath, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name = \"LH60" << i << "_CMD\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_Fb_Out_Lc_Op(std::string& sPath, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name = \"LC60" << i << "_OP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_Fb_Out_Lc_Cmd(std::string& sPath, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name = \"LC60" << i << "_CMD\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_Fb_Out_Sp(std::string& sPath, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name = \"RT60" << i << "_SP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<REAL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_Fb_Out_Lu_Cmd(std::string& sPath, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name = \"LU60" << i << "_CMD\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BOOL/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}

void Knx_Fb_Out_Opm_Out(std::string& sPath, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name = \"OPM_00" << i << "\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<BYTE/>\n\t";
        fOutput << "</type>\n\t";
        fOutput << "</variable>\n\t";
    }
    fOutput.close();
    return;
}



//Funksjoner //nytt ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Knx_Fb_Hvac(std::string& sPath, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int& iAntallT)
{
    std::ofstream fOutput(sPath, std::ios::app);
    if (iAntall > 1)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (30) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Setter Rett OPM</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        for (int i = 0; i < iAntall; i++)
        {
            fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
            fOutput << "<position x=\"" << (14) << "\" y=\"" << (7 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointOut>\n\t";
            fOutput << "<expression />\n\t";
            fOutput << "</connectionPointOut>\n\t";
            fOutput << "<expression>RB60" << (i + 1) << "_HVAC</expression>\n\t";
            fOutput << "</inVariable>\n\t";

            fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
            fOutput << "<position x=\"" << (9 + i) << "\" y=\"" << (275 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"RB60" << (i + 1) << "_HVAC\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</connector>\n\t";

            (*iCfc_Id) += 2;
        }

        fOutput << "<block localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"OR\">\n\t";
        fOutput << "<position x=\"" << (22) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        for (int i = 0; i < iAntall; i++)
        {
            fOutput << "<variable formalParameter=\"In" << (i + 1) << "\">\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (-1 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connection refLocalId=\"" << (2 * (i + 1) + *iCfc_Id - (iAntall * 2)) << "\"/>\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</variable>\n\t";
        }

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";
        if (iAntallT)
        {
            fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
            fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</connector>\n\t";

            fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
            fOutput << "<position x=\"" << (27) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointOut>\n\t";
            fOutput << "<expression />\n\t";
            fOutput << "</connectionPointOut>\n\t";
            fOutput << "<expression>OPM</expression>\n\t";
            fOutput << "</inVariable>\n\t";

            fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
            fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"OPM\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</connector>\n\t";

            fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
            fOutput << "<position x=\"" << (28) << "\" y=\"" << (9 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointOut>\n\t";
            fOutput << "<expression />\n\t";
            fOutput << "</connectionPointOut>\n\t";
            fOutput << "<expression>1</expression>\n\t";
            fOutput << "</inVariable>\n\t";

            fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
            fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"1\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</connector>\n\t";

            fOutput << "<block localId=\"" << (7 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"SEL\">\n\t";
            fOutput << "<position x=\"" << (33) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";

            fOutput << "<inputVariables>\n\t";

            fOutput << "<variable formalParameter=\"In1\">\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</variable>\n\t";

            fOutput << "<variable formalParameter=\"In2\">\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</variable>\n\t";

            fOutput << "<variable formalParameter=\"In3\">\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</variable>\n\t";

            fOutput << "</inputVariables>\n\t";

            fOutput << "<inOutVariables />\n\t";

            fOutput << "<outputVariables>\n\t";

            fOutput << "<variable formalParameter=\"Out1\">\n\t";
            fOutput << "<connectionPointOut>\n\t";
            fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
            fOutput << "<expression />\n\t";
            fOutput << "</connectionPointOut>\n\t";
            fOutput << "</variable>\n\t";

            fOutput << "</outputVariables>\n\t";

            fOutput << "<addData>\n\t";
            fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
            fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
            fOutput << "</data>\n\t";
            fOutput << "</addData>\n\t";
            fOutput << "</block>\n\t";

            fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
            fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</connector>\n\t";

            fOutput << "<outVariable localId=\"" << (9 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\">\n\t";
            fOutput << "<position x=\"" << (40) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "<expression>OPM_CV</expression>\n\t";
            fOutput << "</outVariable>\n\t";

            fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
            fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</connector>\n\t";

            fOutput << "<outVariable localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (3 + *iCfc_Order) << "\">\n\t";
            fOutput << "<position x=\"" << (40) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "<expression>RB600_HVAC</expression>\n\t";
            fOutput << "</outVariable>\n\t";

            (*iCfc_Order) += 4;
            (*iCfc_Id) += 12;
            (*iCfc_y) += (iAntall > 3 ? 19 + iAntall - 3 : 19);
        }
        else
        {

            fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
            fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</connector>\n\t";

            fOutput << "<outVariable localId=\"" << (3 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\">\n\t";
            fOutput << "<position x=\"" << (40) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "<expression>RB600_HVAC</expression>\n\t";
            fOutput << "</outVariable>\n\t";

            (*iCfc_Order) += 3;
            (*iCfc_Id) += 4;
            (*iCfc_y) += (iAntall > 3 ? 18 + iAntall - 3 : 18);
        }


    }
    else if (iAntall > 0 && iAntallT)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (30) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Setter Rett OPM</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (23) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RB601_HVAC</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"RB601_HVAC\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (26) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>OPM</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (11) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"OPM\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (27) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>1</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"1\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";


        fOutput << "<block localId=\"" << (7 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"SEL\">\n\t";
        fOutput << "<position x=\"" << (32) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In3\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (9 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (38) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>OPM_CV</expression>\n\t";
        fOutput << "</outVariable>\n\t";


        (*iCfc_Order) += 2;
        (*iCfc_Id) += 10;
        (*iCfc_y) += 18;
    }
    else
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (30) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Setter Rett OPM</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (29) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>OPM</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"OPM\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (3 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (34) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>OPM_CV</expression>\n\t";
        fOutput << "</outVariable>\n\t";


        (*iCfc_Order) += 1;
        (*iCfc_Id) += 4;
        (*iCfc_y) += 14;

    }

    fOutput.close();
    return;
}




void Knx_Fb_Rt(std::string& sPath, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);

    //OPM
    if (iAntall > 1)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (30) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Setter Temperatur settpunkt</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (23) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>OPM_CV</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"OPM_CV\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (23) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT600_SP_D</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (8) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"RT600_SP_D\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<connector localId=\"" << (5 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (8) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"RT600_SP_D\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (6 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (23) << "\" y=\"" << (9 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT600_SP_S</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (7 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (8) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" formalParameter=\"RT600_SP_S\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (8 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (23) << "\" y=\"" << (10 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT600_SP_N</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (9 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (8) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" formalParameter=\"RT600_SP_N\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (10 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (23) << "\" y=\"" << (11 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT600_SP_F</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (11 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (8) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" formalParameter=\"RT600_SP_F\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";


        fOutput << "<block localId=\"" << (12 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"MUX\">\n\t";
        fOutput << "<position x=\"" << (32) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In3\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In4\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (3 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In5\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In6\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (13 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (14 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (38) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>RT600_CS</expression>\n\t";
        fOutput << "</outVariable>\n\t";
    }
    else
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (30) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Setter Temperatur settpunkt</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (23) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>OPM_CV</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"OPM_CV\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (23) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT601_SP_D</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (8) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"RT601_SP_D\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<connector localId=\"" << (5 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (8) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"RT601_SP_D\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (6 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (23) << "\" y=\"" << (9 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT601_SP_S</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (7 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (8) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" formalParameter=\"RT601_SP_S\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (8 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (23) << "\" y=\"" << (10 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT601_SP_N</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (9 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (8) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" formalParameter=\"RT601_SP_N\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (10 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (23) << "\" y=\"" << (11 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT601_SP_F</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (11 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (8) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" formalParameter=\"RT601_SP_F\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";


        fOutput << "<block localId=\"" << (12 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"MUX\">\n\t";
        fOutput << "<position x=\"" << (32) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In3\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In4\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (3 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In5\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In6\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (13 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (14 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (38) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>RT601_CS</expression>\n\t";
        fOutput << "</outVariable>\n\t";
    }


    (*iCfc_Order) += 2;
    (*iCfc_Id) += 15;
    (*iCfc_y) += 20;

    //Gjennomsnitt ved flere temp
    if (iAntall > 1)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (30) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Beregner temperatur gjennomsnitt</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        for (int i = 0; i < iAntall; i++)
        {
            fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
            fOutput << "<position x=\"" << (16) << "\" y=\"" << (8 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointOut>\n\t";
            fOutput << "<expression />\n\t";
            fOutput << "</connectionPointOut>\n\t";
            fOutput << "<expression>RT60" << (i + 1) << "_CT</expression>\n\t";
            fOutput << "</inVariable>\n\t";

            fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
            fOutput << "<position x=\"" << (9 + i) << "\" y=\"" << (275 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"RT60" << (i + 1) << "_CT\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</connector>\n\t";

            (*iCfc_Id) += 2;
        }

        fOutput << "<block localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"ADD\">\n\t";
        fOutput << "<position x=\"" << (24) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        for (int i = 0; i < iAntall; i++)
        {
            fOutput << "<variable formalParameter=\"In" << (i + 1) << "\">\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (-1 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connection refLocalId=\"" << (2 * (i + 1) + *iCfc_Id - (iAntall * 2)) << "\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</variable>\n\t";
        }

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<connector localId=\"" << (3 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (4 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (30) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>0</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (5 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" formalParameter=\"0\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (6 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"NE\">\n\t";
        fOutput << "<position x=\"" << (35) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (7 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (8 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (37) << "\" y=\"" << (9 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << iAntall << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (9 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" formalParameter=\"" << iAntall << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (10 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\" typeName=\"DIV\">\n\t";
        fOutput << "<position x=\"" << (42) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"EN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ENO\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (11 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (12 + *iCfc_Id) << "\" executionOrderId=\"" << (3 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (48) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>RT600_CT</expression>\n\t";
        fOutput << "</outVariable>\n\t";


        (*iCfc_Order) += 4;
        (*iCfc_Id) += 15;
        (*iCfc_y) += (iAntall > 2 ? 17 + iAntall - 3 : 17);
    }

    fOutput.close();
    return;
}




void Knx_Fb_Ry(std::string& sPath, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);





    if (iAntall > 1)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (30) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Beregner Co2 gjennomsnitt</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        for (int i = 0; i < iAntall; i++)
        {
            fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
            fOutput << "<position x=\"" << (16) << "\" y=\"" << (8 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointOut>\n\t";
            fOutput << "<expression />\n\t";
            fOutput << "</connectionPointOut>\n\t";
            fOutput << "<expression>RY60" << (i + 1) << "_CV</expression>\n\t";
            fOutput << "</inVariable>\n\t";

            fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
            fOutput << "<position x=\"" << (9 + i) << "\" y=\"" << (275 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"RY60" << (i + 1) << "_CV\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</connector>\n\t";

            (*iCfc_Id) += 2;
        }

        fOutput << "<block localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"ADD\">\n\t";
        fOutput << "<position x=\"" << (24) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        for (int i = 0; i < iAntall; i++)
        {
            fOutput << "<variable formalParameter=\"In" << (i + 1) << "\">\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (-1 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connection refLocalId=\"" << (2 * (i + 1) + *iCfc_Id - (iAntall * 2)) << "\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</variable>\n\t";
        }

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<connector localId=\"" << (3 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (4 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (30) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>0</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (5 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" formalParameter=\"0\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (6 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"NE\">\n\t";
        fOutput << "<position x=\"" << (35) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (7 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (8 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (37) << "\" y=\"" << (9 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << iAntall << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (9 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" formalParameter=\"" << iAntall << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (10 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\" typeName=\"DIV\">\n\t";
        fOutput << "<position x=\"" << (42) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"EN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ENO\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (11 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (12 + *iCfc_Id) << "\" executionOrderId=\"" << (3 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (48) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>RY600_CV</expression>\n\t";
        fOutput << "</outVariable>\n\t";


        (*iCfc_Order) += 4;
        (*iCfc_Id) += 15;
        (*iCfc_y) += (iAntall > 2 ? 17 + iAntall - 3 : 17);
    }


    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (30) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Co2 regulering</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    if (iAntall > 1)
    {
        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (22) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RY600_CV</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"RY600_CV\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //SP
        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (22) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RY600_SP</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"RY600_SP\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Kp
        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RY600_PID_Kp</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"RY600_PID_Kp\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Ti
        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (9 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RY600_PID_Ti</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"RY600_PID_Ti\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Td
        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (10 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RY600_PID_Td</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"RY600_PID_Td\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //xMan
        fOutput << "<inVariable localId=\"" << (11 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (21) << "\" y=\"" << (11 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RY600_MAN</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (12 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (11) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"RY600_MAN\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //fMan
        fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (19) << "\" y=\"" << (12 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RY600_PID_fMan</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"RY600_PID_fMan\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbSE_PID\" instanceName=\"RY600_PID\">\n\t";
        fOutput << "<position x=\"" << (30) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ifPv\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifSp\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifKp\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifTi\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (3 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifTd\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ixManMode\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifManMv\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (14 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"qfMv\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (16 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (15 + *iCfc_Id) << "\" formalParameter=\"qfMv\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (17 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (41) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (16 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>RY600_OP</expression>\n\t";
        fOutput << "</outVariable>\n\t";
    }
    else
    {
        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (22) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RY601_CV</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"RY601_CV\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //SP
        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (22) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RY601_SP</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"RY601_SP\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Kp
        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RY601_PID_Kp</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"RY601_PID_Kp\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Ti
        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (9 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RY601_PID_Ti</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"RY601_PID_Ti\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Td
        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (10 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RY601_PID_Td</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"RY601_PID_Td\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //xMan
        fOutput << "<inVariable localId=\"" << (11 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (21) << "\" y=\"" << (11 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RY601_MAN</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (12 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (11) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"RY601_MAN\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //fMan
        fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (19) << "\" y=\"" << (12 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RY601_PID_fMan</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"RY601_PID_fMan\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbSE_PID\" instanceName=\"RY601_PID\">\n\t";
        fOutput << "<position x=\"" << (30) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ifPv\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifSp\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifKp\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifTi\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (3 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifTd\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ixManMode\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifManMv\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (14 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"qfMv\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (16 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (15 + *iCfc_Id) << "\" formalParameter=\"qfMv\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (17 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (41) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (16 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>RY601_OP</expression>\n\t";
        fOutput << "</outVariable>\n\t";
    }

    (*iCfc_Order) += 2;
    (*iCfc_Id) += 18;
    (*iCfc_y) += 20;

    fOutput.close();
    return;
}




void Knx_Fb_Lh_Op(std::string& sPath, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int& iAntallT)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (30) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Varme regulering</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    if (iAntallT > 1)
    {
        //CT
        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (22) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT600_CT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (10) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"RT600_CT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //SP
        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (22) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT600_CS</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"RT600_CS\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Kp
        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LH600_PID_Kp</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"LH600_PID_Kp\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Ti
        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (9 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LH600_PID_Ti</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"LH600_PID_Ti\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Td
        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (10 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LH600_PID_Td</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"LH600_PID_Td\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //xMan
        fOutput << "<inVariable localId=\"" << (11 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (21) << "\" y=\"" << (11 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LH600_MAN</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (12 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"LH600_MAN\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //rMan
        fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (19) << "\" y=\"" << (12 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LH600_PID_fMan</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"LH600_PID_fMan\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbSE_PID\" instanceName=\"LH600_PID\">\n\t";
        fOutput << "<position x=\"" << (30) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ifPv\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifSp\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifKp\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifTi\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (3) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifTd\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (4) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ixManMode\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (5) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifManMv\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (6) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (14 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"qfMv\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        for (int i = 0; i < iAntall; i++)
        {
            fOutput << "<connector localId=\"" << (16 + i * 2 + *iCfc_Id) << "\" name=\"\">\n\t";
            fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<connection refLocalId=\"" << (15 + *iCfc_Id) << "\" formalParameter=\"qfMv\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</connector>\n\t";

            fOutput << "<outVariable localId=\"" << (17 + i * 2 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + i + *iCfc_Order) << "\">\n\t";
            fOutput << "<position x=\"" << (42) << "\" y=\"" << (6 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connection refLocalId=\"" << (16 + i * 2 + *iCfc_Id) << "\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "<expression>LH60" << i + 1 << "_OP</expression>\n\t";
            fOutput << "</outVariable>\n\t";
        }
        (*iCfc_Id) += (iAntall - 1) * 2;
        (*iCfc_Order) += (iAntall - 1);
    }
    else
    {
        //CT
        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (22) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT601_CT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (10) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"RT601_CT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //SP
        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (22) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT601_CS</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"RT601_CS\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Kp
        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LH601_PID_Kp</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"LH601_PID_Kp\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Ti
        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (9 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LH601_PID_Ti</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"LH601_PID_Ti\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Td
        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (10 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LH601_PID_Td</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"LH601_PID_Td\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //xMan
        fOutput << "<inVariable localId=\"" << (11 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (21) << "\" y=\"" << (11 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LH601_MAN</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (12 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"LH601_MAN\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //rMan
        fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (19) << "\" y=\"" << (12 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LH601_PID_fMan</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"LH601_PID_fMan\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbSE_PID\" instanceName=\"LH601_PID\">\n\t";
        fOutput << "<position x=\"" << (30) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ifPv\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifSp\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifKp\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifTi\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (3) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifTd\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (4) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ixManMode\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (5) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifManMv\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (6) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (14 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"qfMv\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (16 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (15 + *iCfc_Id) << "\" formalParameter=\"qfMv\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (17 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (41) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (16 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>LH601_OP</expression>\n\t";
        fOutput << "</outVariable>\n\t";
    }

    (*iCfc_Order) += 2;
    (*iCfc_Id) += 18;
    (*iCfc_y) += 20;

    fOutput.close();
    return;
}




void Knx_Fb_Lh_Cmd(std::string& sPath, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int& iAntallT)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (30) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Varme regulering</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    //CT
    if (iAntallT > 1)
    {
        //SP
        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT600_CS</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"RT600_CS\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //CT
        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT600_CT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"RT600_CT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Sub
        fOutput << "<block localId=\"" << (5 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"SUB\">\n\t";
        fOutput << "<position x=\"" << (28) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";


        //Differanse fra sub
        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //On
        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (19) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LH600_T_On</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"LH600_T_On\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Off
        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (19) << "\" y=\"" << (9 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LH600_T_Off</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"LH600_T_Off\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";





        fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"fbSE_Hyst\" instanceName=\"LH600_T\">\n\t";
        fOutput << "<position x=\"" << (35) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"rIn\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"rOn\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"rOff\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"xOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        for (int i = 0; i < iAntall; i++)
        {
            fOutput << "<connector localId=\"" << (12 + i * 2 + *iCfc_Id) << "\" name=\"\">\n\t";
            fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"xOut\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</connector>\n\t";

            fOutput << "<outVariable localId=\"" << (13 + i * 2 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + i + *iCfc_Order) << "\">\n\t";
            fOutput << "<position x=\"" << (45) << "\" y=\"" << (7 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connection refLocalId=\"" << (12 + i * 2 + *iCfc_Id) << "\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "<expression>LH60" << i + 1 << "_CMD</expression>\n\t";
            fOutput << "</outVariable>\n\t";
        }
        (*iCfc_Id) += (iAntall - 1) * 2;
        (*iCfc_Order) += (iAntall - 1);
    }
    else
    {
        //SP
        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT601_CS</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"RT601_CS\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //CT
        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT601_CT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"RT601_CT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Sub
        fOutput << "<block localId=\"" << (5 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"SUB\">\n\t";
        fOutput << "<position x=\"" << (28) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";


        //Differanse fra sub
        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //On
        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (19) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LH601_T_On</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"LH601_T_On\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Off
        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (19) << "\" y=\"" << (9 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LH601_T_Off</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"LH601_T_Off\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";





        fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"fbSE_Hyst\" instanceName=\"LH601_T\">\n\t";
        fOutput << "<position x=\"" << (35) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"rIn\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"rOn\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"rOff\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"xOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (12 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"xOut\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (13 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (44) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>LH601_CMD</expression>\n\t";
        fOutput << "</outVariable>\n\t";
    }

    (*iCfc_Order) += 3;
    (*iCfc_Id) += 14;
    (*iCfc_y) += 20;

    fOutput.close();
    return;
}




void Knx_Fb_Lc_Op(std::string& sPath, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int& iAntallT)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (30) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Kjoele regulering</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    if (iAntallT > 1)
    {
        //CT
        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (22) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT600_CT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"RT600_CT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //SP
        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (22) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT600_CS</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"RT600_CS\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Kp
        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LC600_PID_Kp</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"LC600_PID_Kp\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Ti
        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (9 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LC600_PID_Ti</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"LC600_PID_Ti\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Td
        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (10 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LC600_PID_Td</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"LC600_PID_Td\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //xMan
        fOutput << "<inVariable localId=\"" << (11 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (21) << "\" y=\"" << (11 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LC600_MAN</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (12 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"LC600_MAN\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //fMan
        fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (19) << "\" y=\"" << (12 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LC600_PID_fMan</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"LC600_PID_fMan\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbSE_PID\" instanceName=\"LC600_PID\">\n\t";
        fOutput << "<position x=\"" << (30) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ifPv\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifSp\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifKp\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifTi\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (3) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifTd\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (4) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ixManMode\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (5) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifManMv\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (6) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (14 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"qfMv\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        for (int i = 0; i < iAntall; i++)
        {
            fOutput << "<connector localId=\"" << (16 + i * 2 + *iCfc_Id) << "\" name=\"\">\n\t";
            fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<connection refLocalId=\"" << (15 + *iCfc_Id) << "\" formalParameter=\"qfMv\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</connector>\n\t";

            fOutput << "<outVariable localId=\"" << (17 + i * 2 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + i + *iCfc_Order) << "\">\n\t";
            fOutput << "<position x=\"" << (42) << "\" y=\"" << (6 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connection refLocalId=\"" << (16 + i * 2 + *iCfc_Id) << "\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "<expression>LC60" << i + 1 << "_OP</expression>\n\t";
            fOutput << "</outVariable>\n\t";
        }
        (*iCfc_Id) += (iAntall - 1) * 2;
        (*iCfc_Order) += (iAntall - 1);
    }
    else
    {
        //CT
        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (22) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT601_CT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"RT601_CT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //SP
        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (22) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT601_CS</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"RT601_CS\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Kp
        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LC601_PID_Kp</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"LC601_PID_Kp\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Ti
        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (9 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LC601_PID_Ti</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"LC601_PID_Ti\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Td
        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (10 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LC601_PID_Td</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"LC601_PID_Td\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //xMan
        fOutput << "<inVariable localId=\"" << (11 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (21) << "\" y=\"" << (11 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LC601_MAN</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (12 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"LC601_MAN\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //fMan
        fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (19) << "\" y=\"" << (12 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LC601_PID_fMan</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"LC601_PID_fMan\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbSE_PID\" instanceName=\"LC601_PID\">\n\t";
        fOutput << "<position x=\"" << (30) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ifPv\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifSp\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifKp\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifTi\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (3) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifTd\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (4) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ixManMode\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (5) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"ifManMv\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (6) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (14 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"qfMv\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (16 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (15 + *iCfc_Id) << "\" formalParameter=\"qfMv\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (17 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (41) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (16 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>LC601_OP</expression>\n\t";
        fOutput << "</outVariable>\n\t";
    }

    if (iAntall > 1)
    {
    }
    else
    {
    }


    (*iCfc_Order) += 2;
    (*iCfc_Id) += 18;
    (*iCfc_y) += 20;

    fOutput.close();
    return;
}




void Knx_Fb_Lc_Cmd(std::string& sPath, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int& iAntallT)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (30) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Kjoele regulering</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";


    //CT
    if (iAntallT > 1)
    {
        //SP
        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT600_CS</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"RT600_CS\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //CT
        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT600_CT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"RT600_CT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Sub
        fOutput << "<block localId=\"" << (5 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"SUB\">\n\t";
        fOutput << "<position x=\"" << (28) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";


        //Differanse fra sub
        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //On
        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (19) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LC600_T_On</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"LC600_T_On\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Off
        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (19) << "\" y=\"" << (9 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LC600_T_Off</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"LC600_T_Off\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";





        fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"fbSE_Hyst\" instanceName=\"LC600_T\">\n\t";
        fOutput << "<position x=\"" << (35) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"rIn\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"rOn\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"rOff\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"xOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        for (int i = 0; i < iAntall; i++)
        {
            fOutput << "<connector localId=\"" << (12 + i * 2 + *iCfc_Id) << "\" name=\"\">\n\t";
            fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"xOut\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</connector>\n\t";

            fOutput << "<outVariable localId=\"" << (13 + i * 2 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + i + *iCfc_Order) << "\">\n\t";
            fOutput << "<position x=\"" << (45) << "\" y=\"" << (7 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + i + *iCfc_y) << "\" />\n\t";
            fOutput << "<connection refLocalId=\"" << (12 + i * 2 + *iCfc_Id) << "\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "<expression>LC60" << i + 1 << "_CMD</expression>\n\t";
            fOutput << "</outVariable>\n\t";
        }
        (*iCfc_Id) += (iAntall - 1) * 2;
        (*iCfc_Order) += (iAntall - 1);
    }
    else
    {
        //SP
        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT601_CS</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"RT601_CS\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //CT
        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (20) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>RT601_CT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"RT601_CT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Sub
        fOutput << "<block localId=\"" << (5 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"SUB\">\n\t";
        fOutput << "<position x=\"" << (28) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";


        //Differanse fra sub
        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //On
        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (19) << "\" y=\"" << (8 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LC601_T_On</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"LC601_T_On\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        //Off
        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (19) << "\" y=\"" << (9 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>LC601_T_Off</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"LC601_T_Off\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";





        fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"fbSE_Hyst\" instanceName=\"LC601_T\">\n\t";
        fOutput << "<position x=\"" << (35) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"rIn\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"rOn\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"rOff\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables />\n\t";

        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"xOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";

        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (12 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"xOut\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (13 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (44) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>LC601_CMD</expression>\n\t";
        fOutput << "</outVariable>\n\t";
    }

    (*iCfc_Order) += 3;
    (*iCfc_Id) += 14;
    (*iCfc_y) += 20;

    fOutput.close();
    return;
}









//PID og Hysterese blokker
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Fb_Hyst(std::string& sPath)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<pou name = \"fbSE_Hyst\" pouType = \"functionBlock\">\n\t";
    fOutput << "<interface>\n\t";
    fOutput << "<inputVars>\n\t";

    fOutput << "<variable name = \"rIn\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable name = \"rOn\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable name = \"rOff\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "</variable>\n\t";


    fOutput << "</inputVars>\n\t";
    fOutput << "<localVars/>\n\t";
    fOutput << "<outputVars>\n\t";

    fOutput << "<variable name = \"xOut\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<BOOL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "</outputVars>\n\t";
    fOutput << "</interface>\n" + Tabs(3);
    fOutput << "<body>\n" + Tabs(4);
    fOutput << "<ST>" << std::endl << Tabs(5);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">";

    fOutput << "xOut:= ((rOn &gt; rOff AND (rIn &gt;= rOn OR (xOut AND rIn &gt; rOff)))	OR		(rOn &lt;rOff AND (rIn &lt;= rOn OR (xOut AND rIn &lt;rOff))));";

    fOutput << "</xhtml>\n" + Tabs(4);
    fOutput << "</ST>\n" + Tabs(3);
    fOutput << "</body>\n" + Tabs(3);
    fOutput << "<addData/>\n" + Tabs(2);
    fOutput << "</pou>\n" + Tabs(1);

    fOutput.close();
    return;
}

//Importerer PID hvis den er brukt
void Fb_Pid(std::string& sPath)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<pou name = \"fbSE_PID\" pouType = \"functionBlock\">\n\t";
    fOutput << "<interface>\n\t";
    fOutput << "<inputVars>\n\t";

    //PV
    fOutput << "<variable name = \"ifPv\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Prosessvariabel (actual)</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //SP
    fOutput << "<variable name = \"ifSp\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Settpunkt</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Kp
    fOutput << "<variable name = \"ifKp\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<initialValue>\n" + Tabs(7);
    fOutput << "<simpleValue value=\"1\" />\n" + Tabs(6);
    fOutput << "</initialValue>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Forsterkning</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Ti
    fOutput << "<variable name = \"ifTi\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<initialValue>\n" + Tabs(7);
    fOutput << "<simpleValue value=\"10\" />\n" + Tabs(6);
    fOutput << "</initialValue>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">I-tid</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Td
    fOutput << "<variable name = \"ifTd\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">D-tid</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Bias
    fOutput << "<variable name = \"ifBias\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Bias (Statisk paadrag som alltid er der) 0-100%</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Input zero
    fOutput << "<variable name = \"ifInZero\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Nullpunkt for inn-verdi (PV og SP)</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Input max
    fOutput << "<variable name = \"ifInMax\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<initialValue>\n" + Tabs(7);
    fOutput << "<simpleValue value=\"100\" />\n" + Tabs(6);
    fOutput << "</initialValue>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Toppunkt for inn-verdi (PV og SP)</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Output zero
    fOutput << "<variable name = \"ifOutZero\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Nullpunkt for ut-verdi (MV)</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Output max
    fOutput << "<variable name = \"ifOutMax\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<initialValue>\n" + Tabs(7);
    fOutput << "<simpleValue value=\"100\" />\n" + Tabs(6);
    fOutput << "</initialValue>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Toppunkt for ut-verdi (MV)</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Man mode
    fOutput << "<variable name = \"ixManMode\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<BOOL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Sender ManMv som MV, og resetter I-ledd</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Man MV
    fOutput << "<variable name = \"ifManMv\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Manuelt paadrag som brukes i Man mode</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    fOutput << "</inputVars>\n\t";
    fOutput << "<localVars>\n\t";

    //Local vars
    //PV skalert
    fOutput << "<variable name = \"fPv\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Skalert PV (0-100)</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //SP skalert
    fOutput << "<variable name = \"fSp\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Skalert SP (0-100)</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //eRun
    fOutput << "<variable name = \"eRun\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<derived name=\"R_TRIG\" />\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Resetter I-ledd ved endring rising edge i start betingelser</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Avvik
    fOutput << "<variable name = \"fAvvik\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Avvik (Error)</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Syklus timer
    fOutput << "<variable name = \"tCycleTimer\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<derived name=\"TON\" />\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<initialValue>\n\t";
    fOutput << "<structValue>\n\t";
    fOutput << "<value member = \"PT\">\n\t";
    fOutput << "<simpleValue value = \"TIME#1s0ms\" />\n\t";
    fOutput << "</value>\n\t";
    fOutput << "</structValue>\n\t";
    fOutput << "</initialValue>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Teller syklus tiden</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Syklus tid
    fOutput << "<variable name = \"fCycleTime\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Syklus tid i real</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //PID verdi
    fOutput << "<variable name = \"fPID\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">PID resultat (0-100%)</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Forgje forsterkning
    fOutput << "<variable name = \"fLastKp\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Forsterkning sist syklus (brukes til skalering ved endring)</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Forgje Ti
    fOutput << "<variable name = \"fLastTi\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Ti sist syklus (brukes til skalering ved endring)</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Forgje max integral
    fOutput << "<variable name = \"fLastIntegMax\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Max integral verdi sist syklus</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Max integral
    fOutput << "<variable name = \"fIntegMax\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Max integral verdi (beregnet med Ti)</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Integral
    fOutput << "<variable name = \"fIntegral\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Integral verdi</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Integralt avvik
    fOutput << "<variable name = \"fI\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Integralt avvik</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Forgje avvik
    fOutput << "<variable name = \"fLastAvvik\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Avvik sist syklus</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Derivat
    fOutput << "<variable name = \"fDerivat\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Derivat verdi</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Derivert avvik
    fOutput << "<variable name = \"fD\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Derivert avvik</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    fOutput << "</localVars>\n\t";
    fOutput << "<outputVars>\n\t";

    //Out vars
    //MV
    fOutput << "<variable name = \"qfMv\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<REAL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Manipulert verdi (Resultat av PID)</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    //Error
    fOutput << "<variable name = \"qxError\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<BOOL/>\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Feil alarm</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    fOutput << "</outputVars>\n\t";
    fOutput << "</interface>\n" + Tabs(3);
    fOutput << "<body>\n" + Tabs(4);
    fOutput << "<ST>" << std::endl << Tabs(5);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">";




    //Program
    fOutput << "eRun(CLK:= (ifKp &gt; 0 AND NOT ixManMode));\n\n";

    fOutput << "IF ixManMode THEN																//Skriver manuelt SP til utgang\n\t";
    fOutput << "qfMv := ifManMv;\n";
    fOutput << "ELSIF eRun.Q THEN																//Hvis det er rising edge paastart betingelser vil diverse variabler resettes/initializes\n\t";
    fOutput << "fIntegral := 0;\n\t";
    fOutput << "fIntegMax:= fLastIntegMax := 1 / ifKp * (100 / (1 / ifTi));\n\t";
    fOutput << "fLastTi:= ifTi;\n\t";
    fOutput << "fLastKp:= ifKp;\n\t";
    fOutput << "fLastAvvik:= fAvvik;\n\t";
    fOutput << "tCycleTimer(IN:= FALSE);\n\t";
    fOutput << "tCycleTimer(IN:= TRUE);\n";
    fOutput << "ELSIF ifKp &gt; 0 THEN												//Hvis Kp er satt, kjoeres PID funksjon\n\n\t";

    fOutput << "//Felles\n\t\t";
    fOutput << "IF(ifInMax - ifInZero) = 0 THEN											//Sjekker om vi deler paa 0, og gir ut evt. feil\n\t\t";
    fOutput << "qxError := TRUE;\n\t\t";
    fOutput << "RETURN;\n\t";
    fOutput << "ELSE																		//	Ellers omskaleres Inn-verdier fra valgt til 0-100, og feil resettes\n\t\t";
    fOutput << "qxError := FALSE;\n\t\t";
    fOutput << "fPv:= (100 / (ifInMax - ifInZero)) * (ifPv - ifInZero);\n\t\t";
    fOutput << "fSp:= (100 / (ifInMax - ifInZero)) * (ifSP - ifInZero);\n\t";
    fOutput << "END_IF\n\n\t";

    fOutput << "//Teller syklys tid\n\t";
    fOutput << "tCycleTimer();																//Kjoerer TON for aa sjekke hvor lang tid som har gaatt siden forgje utregning\n\t";
    fOutput << "fCycleTime:= 0.001 * TIME_TO_REAL(tCycleTimer.ET);							//Omskalerer syklus tid fra TIME til REAL\n\t";
    fOutput << "tCycleTimer(IN:= FALSE);													//Resetter TON\n\t";
    fOutput << "tCycleTimer(IN:= TRUE);\n\n\n\t";


    fOutput << "//Proporsjonalt avvik\n\t";
    fOutput << "fAvvik:= fSp - fPv;															//Beregner avvik som brukes i P-leddet\n\n\n\t";


    fOutput << "//Integralt avvik\n\t";
    fOutput << "IF ifTi &gt; 0 THEN															//Hvis I er mer en 0, kjoerer vi I-ledd beregning\n\t\t";
    fOutput << "IF ifTi &lt;&gt; fLastTi OR ifKp &lt;&gt; fLastKp THEN								//Hvis Ti eller Kp endrer seg, omskaleres max verdi for integral og den eksisterende integral verdien. Lagrer div variabler til neste sjekk/skalering\n\t\t\t";
    fOutput << "fIntegMax := 1 / ifKp * (100 / (1 / ifTi));\n\t\t\t";
    fOutput << "fIntegral:= (fIntegMax / fLastIntegMax) * fIntegral;\n\t\t\t";
    fOutput << "fLastIntegMax:= fIntegMax;\n\t\t\t";
    fOutput << "fLastTi:= ifTi;\n\t\t\t";
    fOutput << "fLastKp:= ifKp;\n\t\t";
    fOutput << "END_IF\n\n\t\t";

    fOutput << "fIntegral := LIMIT(0, (fIntegral + fAvvik * fCycleTime), fIntegMax);		//Beregner integral\n\n\t\t";

    fOutput << "fI:= (1 / ifTi) * fIntegral;												//Beregner I-verdien\n\n\t";

    fOutput << "ELSE\n\t\t";
    fOutput << "fI := 0;																	//Skriver i til 0 hvis Ti er 0\n\t";
    fOutput << "END_IF\n\n\t";


    fOutput << "//Derivert avvik\n\t";
    fOutput << "IF(fAvvik - fLastAvvik)&lt;&gt; 0  AND ifTd &gt; 0 THEN							//Sjekker om D-ledd er i bruk, og hindrer at vi deler paa 0 ved feil\n\t\t";
    fOutput << "fDerivat := (fAvvik - fLastAvvik) / fCycleTime;							//Deriverer avviket\n\t\t";
    fOutput << "fD:= LIMIT(-100, (ifTd * fDerivat), 100);								//Beregner D-verdien\n\t";
    fOutput << "ELSE\n\t\t";
    fOutput << "fD := 0;\n\t";
    fOutput << "END_IF\n\n\n\t";


    fOutput << "//PID utregnign\n\t";
    fOutput << "fPID:= LIMIT(0, (ifKp * (fAvvik + fI + fD) + ifBias), 100);				//Beregner PID utverdi i 0-100\n\n\t";

    fOutput << "IF(ifOutMax - ifOutZero) = 0 THEN											//Sjekker om vi deler paa 0\n\t\t";
    fOutput << "qxError := TRUE;\n\t";
    fOutput << "ELSE																		//	Hvis ikke, omskaleres ut signal til valgt span og feil resettes\n\t\t";
    fOutput << "qxError := FALSE;\n\t\t";
    fOutput << "qfMv:= ((ifOutMax - ifOutZero) / 100) * fPID + ifOutZero;\n\t";
    fOutput << "END_IF\n\n";

    fOutput << "ELSE																			//Skriver utgang til 0, hvis PID ikke er paa\n\t";
    fOutput << "qfMv := 0;\n";
    fOutput << "END_IF";


    fOutput << "</xhtml>\n" + Tabs(4);
    fOutput << "</ST>\n" + Tabs(3);
    fOutput << "</body>\n" + Tabs(3);
    fOutput << "<addData/>\n" + Tabs(2);
    fOutput << "</pou>\n" + Tabs(1);

    fOutput.close();
    return;
}









//Lokal variabler
void Knx_var_Rb(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RB60" << i << "_V\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbDPT_Switch_pro\" />\n\t";
        fOutput << "</type>\n\t";

        if (*xComment)
        {
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            *xComment = false;
        }

        fOutput << "</variable>\n\t";
        (*iKnx)++;
    }

    fOutput.close();
    return;
}


void Knx_var_Hvac(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RB60" << i << "_HVAC\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbDPT_Switch_pro\" />\n\t";
        fOutput << "</type>\n\t";

        if (*xComment)
        {
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            *xComment = false;
        }

        fOutput << "</variable>\n\t";
        (*iKnx)++;
    }

    fOutput.close();
    return;
}


void Knx_var_Rt(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RT60" << i << "_CT\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbDPT_Value_Temp_pro\" />\n\t";
        fOutput << "</type>\n\t";

        if (*xComment)
        {
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            *xComment = false;
        }

        fOutput << "</variable>\n\t";
        (*iKnx)++;
    }

    fOutput.close();
    return;
}

void Knx_var_Ry(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RY60" << i << "_CV\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbDPT_Value_AirQuality_pro\" />\n\t";
        fOutput << "</type>\n\t";

        if (*xComment)
        {
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            *xComment = false;
        }

        fOutput << "</variable>\n\t";
        (*iKnx)++;
    }

    fOutput.close();
    return;
}

void Knx_var_Lh_OP(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LH60" << i << "_OP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbDPT_Scaling_pro\" />\n\t";
        fOutput << "</type>\n\t";

        if (*xComment)
        {
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            *xComment = false;
        }

        fOutput << "</variable>\n\t";
        (*iKnx)++;
    }

    fOutput.close();
    return;
}

void Knx_var_Lh_CMD(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LH60" << i << "_CMD\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbDPT_Switch_pro\" />\n\t";
        fOutput << "</type>\n\t";

        if (*xComment)
        {
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            *xComment = false;
        }

        fOutput << "</variable>\n\t";
        (*iKnx)++;
    }

    fOutput.close();
    return;
}

void Knx_var_Lc_OP(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LC60" << i << "_OP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbDPT_Scaling_pro\" />\n\t";
        fOutput << "</type>\n\t";

        if (*xComment)
        {
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            *xComment = false;
        }

        fOutput << "</variable>\n\t";
        (*iKnx)++;
    }

    fOutput.close();
    return;
}

void Knx_var_Lc_CMD(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LC60" << i << "_CMD\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbDPT_Switch_pro\" />\n\t";
        fOutput << "</type>\n\t";

        if (*xComment)
        {
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            *xComment = false;
        }

        fOutput << "</variable>\n\t";
        (*iKnx)++;
    }

    fOutput.close();
    return;
}

void Knx_var_Sp(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RT60" << i << "_SP\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbDPT_Value_Temp_pro\" />\n\t";
        fOutput << "</type>\n\t";

        if (*xComment)
        {
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            *xComment = false;
        }

        fOutput << "</variable>\n\t";
        (*iKnx)++;
    }

    fOutput.close();
    return;
}

void Knx_var_Sp_Fb(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RT60" << i << "_SP_FB\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbDPT_Value_Temp_pro\" />\n\t";
        fOutput << "</type>\n\t";

        if (*xComment)
        {
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            *xComment = false;
        }

        fOutput << "</variable>\n\t";
        (*iKnx)++;
    }

    fOutput.close();
    return;
}

void Knx_var_Lu_V(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LU60" << i << "_V\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbDPT_Switch_pro\" />\n\t";
        fOutput << "</type>\n\t";

        if (*xComment)
        {
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            *xComment = false;
        }

        fOutput << "</variable>\n\t";
        (*iKnx)++;
    }

    fOutput.close();
    return;
}

void Knx_var_Lu_Al(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LU60" << i << "_AL\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbDPT_Switch_pro\" />\n\t";
        fOutput << "</type>\n\t";

        if (*xComment)
        {
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            *xComment = false;
        }

        fOutput << "</variable>\n\t";
        (*iKnx)++;
    }

    fOutput.close();
    return;
}

void Knx_var_Lu_Cmd(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LU60" << i << "_CMD\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbDPT_Switch_pro\" />\n\t";
        fOutput << "</type>\n\t";

        if (*xComment)
        {
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            *xComment = false;
        }

        fOutput << "</variable>\n\t";
        (*iKnx)++;
    }

    fOutput.close();
    return;
}

void Knx_var_Opm_Out(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_OPM_00" << i << "\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"fbDPT_1_BYTE\" />\n\t";
        fOutput << "</type>\n\t";

        if (*xComment)
        {
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            *xComment = false;
        }

        fOutput << "</variable>\n\t";
        (*iKnx)++;
    }

    fOutput.close();
    return;
}

void Knx_var_Rh_Cv(std::string& sPath, int& iMaster, int* iKnx, std::string& sRom, bool* xComment, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable name=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RH60" << i << "_CV\">\n\t";
        fOutput << "<type>\n\t";
        fOutput << "<derived name=\"FbDPT_Value_Humidity_pro\" />\n\t";
        fOutput << "</type>\n\t";

        if (*xComment)
        {
            fOutput << "<documentation>\n" + Tabs(7);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
            fOutput << "</documentation>\n" + Tabs(5);
            *xComment = false;
        }

        fOutput << "</variable>\n\t";
        (*iKnx)++;
    }

    fOutput.close();
    return;
}












//----------------------------------------------------------------------------------------------------------------------------------------
//CFC koder










void Knx_cfc_comment_a(std::string& sPath, std::string& sRom, int* iCfc_Id, int& iCfc_y)        //kommentar på venstre siden
{
    std::ofstream fOutput(sPath, std::ios::app);
    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"23\" y=\"" << (21 + iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Rom " << sRom << "</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    (*iCfc_Id)++;
}

void Knx_cfc_comment_b(std::string& sPath, std::string& sRom, int* iCfc_Id, int& iCfc_y)        //Kommentar høyre side
{
    std::ofstream fOutput(sPath, std::ios::app);
    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"65\" y=\"" << (21 + iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Rom " << sRom << "</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    (*iCfc_Id)++;
}










void Knx_cfc_Master(std::string& sPath, std::string& sGvl, std::string& sAdresseFormat, int& iMaster, int* iCfc_Order, int* iCfc_Id)
{
    std::ofstream fOutput(sPath, std::ios::app);


    //Kommentar
    fOutput << "<comment localId = \"" << (1 + *iCfc_Id) << "\" height = \"0\" width = \"0\">\n\t";
    fOutput << "<position x = \"65\" y = \"3\"/>\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns = \"http://www.w3.org/1999/xhtml\"> KNX Master</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    //KNX kort
    fOutput << "<inVariable localId = \"" << (2 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x = \"46\" y = \"7\"/>\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression/>\n\t";
    fOutput << "</connectionPointOut>\n\t";

    if (iMaster == 1)
        fOutput << "<expression>_753_646_24</expression>\n\t";
    else
        fOutput << "<expression>_753_646_24_" << (iMaster - 1) << "</expression>\n\t";

    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId = \"" << (3 + *iCfc_Id) << "\" name = \"\">\n\t";
    fOutput << "<position x = \"13\" y = \"7\"/>\n\t";
    fOutput << "<connectionPointIn>\n\t";

    if (iMaster == 1)
        fOutput << "<connection refLocalId = \"" << (2 + *iCfc_Id) << "\" formalParameter = \"_753_646_24\"/>\n\t";
    else
        fOutput << "<connection refLocalId = \"" << (2 + *iCfc_Id) << "\" formalParameter = \"_753_646_24_" << (iMaster - 1) << "\"/>\n\t";


    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    //Linje
    fOutput << "<inVariable localId = \"" << (4 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x = \"60\" y = \"8\"/>\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression/>\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << iMaster << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId = \"" << (5 + *iCfc_Id) << "\" name = \"\">\n\t";
    fOutput << "<position x = \"-8\" y = \"-2\"/>\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId = \"" << (4 + *iCfc_Id) << "\" formalParameter = \"" << iMaster << "\"/>\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    //Master blokk
    fOutput << "<block localId = \"" << (6 + *iCfc_Id) << "\" executionOrderId = \"" << (1 + *iCfc_Order) << "\" typeName = \"WagoAppKNX.FbKNX_Master\" instanceName = \"KNX_master_" << iMaster << "\">\n\t";
    fOutput << "<position x = \"65\" y = \"5\"/>\n\t";

    //Inputs
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter = \"I_Port\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x = \"0\" y = \"0\"/>\n\t";
    fOutput << "<connection refLocalId = \"" << (3 + *iCfc_Id) << "\"/>\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter = \"bPortKNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x = \"0\" y = \"1\"/>\n\t";
    fOutput << "<connection refLocalId = \"" << (5 + *iCfc_Id) << "\"/>\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "</inputVariables>\n\t";

    fOutput << "<inOutVariables/>\n\t";

    fOutput << "<outputVariables>\n\t";

    //Outputs
    fOutput << "<variable formalParameter = \"oStatus\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x = \"0\" y = \"0\"/>\n\t";
    fOutput << "<expression/>\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter = \"sStatus\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x = \"0\" y = \"1\"/>\n\t";
    fOutput << "<expression/>\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter = \"xProgMode\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x = \"0\" y = \"2\"/>\n\t";
    fOutput << "<expression/>\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter = \"wCountFbDPT\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x = \"0\" y = \"3\"/>\n\t";
    fOutput << "<expression/>\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</outputVariables>\n\t";

    fOutput << "<addData>\n\t";
    fOutput << "<data name = \"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown = \"implementation\">\n\t";
    fOutput << "<CallType xmlns = \"\">functionblock</CallType>\n\t";
    fOutput << "</data>\n\t";
    fOutput << "</addData>\n\t";
    fOutput << "</block>\n\t";

    //connectors og var til eq blokk
    fOutput << "<connector localId = \"" << (7 + *iCfc_Id) << "\" name = \"\">\n\t";
    fOutput << "<position x = \"-9\" y = \"-3\"/>\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId = \"" << (6 + *iCfc_Id) << "\" formalParameter = \"sStatus\"/>\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId = \"" << (8 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x = \"80\" y = \"9\"/>\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression/>\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>'OK'</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId = \"" << (9 + *iCfc_Id) << "\" name = \"\">\n\t";
    fOutput << "<position x = \"-55\" y = \"-9\"/>\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId = \"" << (8 + *iCfc_Id) << "\" formalParameter = \"'OK'\"/>\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    //EQ blokk
    fOutput << "<block localId = \"" << (10 + *iCfc_Id) << "\" executionOrderId = \"" << (2 + *iCfc_Order) << "\" typeName = \"EQ\">\n\t";
    fOutput << "<position x = \"85\" y = \"6\"/>\n\t";

    fOutput << "<inputVariables>\n\t";

    fOutput << "<variable formalParameter = \"In1\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x = \"0\" y = \"0\"/>\n\t";
    fOutput << "<connection refLocalId = \"" << (7 + *iCfc_Id) << "\"/>\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter = \"In2\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x = \"0\" y = \"1\"/>\n\t";
    fOutput << "<connection refLocalId = \"" << (9 + *iCfc_Id) << "\"/>\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "</inputVariables>\n\t";

    fOutput << "<inOutVariables/>\n\t";

    fOutput << "<outputVariables>\n\t";

    fOutput << "<variable formalParameter = \"Out1\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x = \"0\" y = \"0\"/>\n\t";
    fOutput << "<expression/>\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</outputVariables>\n\t";

    fOutput << "<addData>\n\t";
    fOutput << "<data name = \"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown = \"implementation\">\n\t";
    fOutput << "<CallType xmlns = \"\">operator</CallType>\n\t";
    fOutput << "</data>\n\t";
    fOutput << "</addData>\n\t";
    fOutput << "</block>\n\t";

    fOutput << "<connector localId = \"" << (11 + *iCfc_Id) << "\" name = \"\">\n\t";
    fOutput << "<position x = \"-55\" y = \"-9\"/>\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId = \"" << (10 + *iCfc_Id) << "\" formalParameter = \"\"/>\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId = \"" << (12 + *iCfc_Id) << "\" executionOrderId = \"" << (3 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x = \"90\" y = \"8\"/>\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x = \"0\" y = \"0\"/>\n\t";
    fOutput << "<connection refLocalId = \"" << (11 + *iCfc_Id) << "\"/>\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGvl << "." << sAdresseFormat << "_KNX_Card_" << iMaster << "_Status</expression>\n\t";
    fOutput << "</outVariable>\n\t";


    (*iCfc_Id) += 13;
    (*iCfc_Order) += 4;
    fOutput.close();
    return;
}










void Knx_cfc_Interval(std::string& sPath, int& iKnxOutputs)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<comment localId=\"0\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"7\" y=\"3\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">KNX Sending interval</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    fOutput << "<inVariable localId=\"1\">\n\t";
    fOutput << "<position x=\"2\" y=\"7\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>Interval.Q</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"2\" name=\"\">\n\t";
    fOutput << "<position x=\"1\" y=\"150\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"1\" formalParameter=\"Interval.Q\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"3\" executionOrderId=\"0\" typeName=\"TON\" instanceName=\"Interval\">\n\t";
    fOutput << "<position x=\"11\" y=\"5\" />\n\t";

    fOutput << "<inputVariables>\n\t";

    fOutput << "<variable formalParameter=\"IN\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
    fOutput << "<connection refLocalId=\"2\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables />\n\t";
    fOutput << "<outputVariables>\n\t";

    fOutput << "<variable formalParameter=\"Q\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "</outputVariables>\n\t";

    fOutput << "<addData>\n\t";
    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
    fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
    fOutput << "</data>\n\t";
    fOutput << "</addData>\n\t";
    fOutput << "</block>\n\t";

    fOutput << "<connector localId=\"4\" name=\"\">\n\t";
    fOutput << "<position x=\"11\" y=\"184\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"3\" formalParameter=\"Q\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"5\" executionOrderId=\"1\" typeName=\"BOOL_TO_INT\">\n\t";
    fOutput << "<position x=\"20\" y=\"5\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"In1\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
    fOutput << "<connection refLocalId=\"4\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables />\n\t";
    fOutput << "<outputVariables>\n\t";
    fOutput << "<variable formalParameter=\"Out1\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</outputVariables>\n\t";
    fOutput << "<addData>\n\t";
    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
    fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
    fOutput << "</data>\n\t";
    fOutput << "</addData>\n\t";
    fOutput << "</block>\n\t";
    fOutput << "<connector localId=\"6\" name=\"\">\n\t";
    fOutput << "<position x=\"11\" y=\"184\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"5\" formalParameter=\"\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<inVariable localId=\"7\">\n\t";
    fOutput << "<position x=\"25\" y=\"9\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>i</expression>\n\t";
    fOutput << "</inVariable>\n\t";
    fOutput << "<connector localId=\"8\" name=\"\">\n\t";
    fOutput << "<position x=\"11\" y=\"184\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"7\" formalParameter=\"i\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<block localId=\"9\" executionOrderId=\"2\" typeName=\"ADD\">\n\t";
    fOutput << "<position x=\"31\" y=\"5\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"In1\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
    fOutput << "<connection refLocalId=\"6\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"In2\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
    fOutput << "<connection refLocalId=\"8\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables />\n\t";
    fOutput << "<outputVariables>\n\t";
    fOutput << "<variable formalParameter=\"Out1\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</outputVariables>\n\t";
    fOutput << "<addData>\n\t";
    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
    fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
    fOutput << "</data>\n\t";
    fOutput << "</addData>\n\t";
    fOutput << "</block>\n\t";
    fOutput << "<connector localId=\"10\" name=\"\">\n\t";
    fOutput << "<position x=\"11\" y=\"184\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"9\" formalParameter=\"\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<outVariable localId=\"11\" executionOrderId=\"3\">\n\t";
    fOutput << "<position x=\"36\" y=\"7\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
    fOutput << "<connection refLocalId=\"10\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>i</expression>\n\t";
    fOutput << "</outVariable>\n\t";
    fOutput << "<connector localId=\"12\" name=\"\">\n\t";
    fOutput << "<position x=\"11\" y=\"184\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"7\" formalParameter=\"i\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<inVariable localId=\"13\">\n\t";
    fOutput << "<position x=\"25\" y=\"12\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";

    fOutput << "<expression>" << iKnxOutputs << "</expression>\n\t";

    fOutput << "</inVariable>\n\t";
    fOutput << "<connector localId=\"14\" name=\"\">\n\t";
    fOutput << "<position x=\"11\" y=\"184\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"13\" formalParameter=\"" << iKnxOutputs << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"15\" executionOrderId=\"4\" typeName=\"GT\">\n\t";
    fOutput << "<position x=\"31\" y=\"9\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"In1\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
    fOutput << "<connection refLocalId=\"12\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"In2\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
    fOutput << "<connection refLocalId=\"14\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables />\n\t";
    fOutput << "<outputVariables>\n\t";
    fOutput << "<variable formalParameter=\"Out1\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</outputVariables>\n\t";
    fOutput << "<addData>\n\t";
    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
    fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
    fOutput << "</data>\n\t";
    fOutput << "</addData>\n\t";
    fOutput << "</block>\n\t";
    fOutput << "<connector localId=\"16\" name=\"\">\n\t";
    fOutput << "<position x=\"11\" y=\"184\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"15\" formalParameter=\"\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"17\">\n\t";
    fOutput << "<position x=\"36\" y=\"12\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>0</expression>\n\t";
    fOutput << "</inVariable>\n\t";
    fOutput << "<connector localId=\"18\" name=\"\">\n\t";
    fOutput << "<position x=\"11\" y=\"184\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"17\" formalParameter=\"0\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"19\" executionOrderId=\"5\" typeName=\"MOVE\">\n\t";
    fOutput << "<position x=\"41\" y=\"9\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"EN\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
    fOutput << "<connection refLocalId=\"16\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"In2\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
    fOutput << "<connection refLocalId=\"18\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables />\n\t";
    fOutput << "<outputVariables>\n\t";

    fOutput << "<variable formalParameter=\"ENO\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"Out2\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "</outputVariables>\n\t";
    fOutput << "<addData>\n\t";
    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
    fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
    fOutput << "</data>\n\t";
    fOutput << "</addData>\n\t";
    fOutput << "</block>\n\t";

    fOutput << "<connector localId=\"20\" name=\"\">\n\t";
    fOutput << "<position x=\"11\" y=\"19\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"19\" formalParameter=\"\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<outVariable localId=\"21\" executionOrderId=\"6\">\n\t";
    fOutput << "<position x=\"48\" y=\"12\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
    fOutput << "<connection refLocalId=\"20\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>i</expression>\n\t";
    fOutput << "</outVariable>\n\t";
    fOutput.close();
    return;
}









void Knx_cfc_Rb(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int& iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int* iCfc_x, bool* xSpace, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (25 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">RB60" << i << "_V</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (1 + 29 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << iMaster << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 454 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << iMaster << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (1 + 30 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnx << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 454 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (1 + 35 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>typDPT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 454 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (7 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbDPT_Switch_pro\" instanceName=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RB60" << i << "_V\">\n\t";

        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (1 + 27 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xSwitch_IN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 3 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 4 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 5 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables>\n\t";
        fOutput << "<variable formalParameter=\"typDPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inOutVariables>\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"xSwitch_OUT\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 288 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"xSwitch_OUT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<connector localId=\"" << (9 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 288 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"xUpdate_PLC\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";


        //Nytt
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        fOutput << "<block localId=\"" << (10 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"MOVE\">\n\t";
        fOutput << "<position x=\"" << (23 + 16 + *iCfc_x) << "\" y=\"" << (29 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"EN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables />\n\t";
        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ENO\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"Out2\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (11 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 288 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        fOutput << "<outVariable localId=\"" << (12 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (37 + 8 + *iCfc_x) << "\" y=\"" << (32 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";

        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RB60" << i << "_V</expression>\n\t";

        fOutput << "</outVariable>\n\t";

        (*iCfc_Id) += 13;
        (*iCfc_Order) += 3;
        (*iKnx)++;

        if (*iCfc_x >= 40)
        {
            (*iCfc_x) = 2;
            (*iCfc_y) += 18;
            *xSpace = true;
        }
        else
        {
            *iCfc_x += 48;
            *xSpace = false;
        }
    }

    fOutput.close();
    return;
}







void Knx_cfc_Hvac(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int& iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int* iCfc_x, bool* xSpace, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (25 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">RB60" << i << "_HVAC</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";
        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (30 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";

        fOutput << "<expression>" << iMaster << "</expression >\n\t";

        fOutput << "</inVariable>\n\t";
        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (455 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << iMaster << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";
        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (31 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";

        fOutput << "<expression>" << *iKnx << "</expression >\n\t";

        fOutput << "</inVariable>\n\t";
        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (455 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";
        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (36 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>typDPT</expression>\n\t";
        fOutput << "</inVariable>\n\t";
        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (455 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (7 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbDPT_Switch_pro\" instanceName=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RB60" << i << "_HVAC\">\n\t";

        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (28 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xSwitch_IN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + 3 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + 4 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + 5 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables>\n\t";
        fOutput << "<variable formalParameter=\"typDPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + 6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inOutVariables>\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"xSwitch_OUT\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (289 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"xSwitch_OUT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";




        //Nytt
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        fOutput << "<connector localId=\"" << (9 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (289 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"xUpdate_PLC\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (10 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"MOVE\">\n\t";
        fOutput << "<position x=\"" << (23 + 16 + *iCfc_x) << "\" y=\"" << (29 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"EN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables />\n\t";
        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ENO\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"Out2\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (11 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 288 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        fOutput << "<outVariable localId=\"" << (12 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (37 + 8 + *iCfc_x) << "\" y=\"" << (32 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";

        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RB60" << i << "_HVAC</expression>\n\t";

        fOutput << "</outVariable>\n\t";


        (*iCfc_Id) += 13;
        (*iCfc_Order) += 3;
        (*iKnx)++;

        if (*iCfc_x >= 40)
        {
            (*iCfc_x) = 2;
            (*iCfc_y) += 18;
            *xSpace = true;
        }
        else
        {
            *iCfc_x += 48;
            *xSpace = false;
        }
    }

    fOutput.close();
    return;
}









void Knx_cfc_Rt(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int& iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int* iCfc_x, bool* xSpace, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (25 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">RT60" << i << "_CT</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (30 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";

        fOutput << "<expression>" << iMaster << "</expression>\n\t";

        fOutput << "</inVariable>\n\t";
        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << iMaster << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";
        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (31 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";

        fOutput << "<expression>" << *iKnx << "</expression>\n\t";

        fOutput << "</inVariable>\n\t";
        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";
        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (37 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";

        fOutput << "<expression>typDPT</expression>\n\t";

        fOutput << "</inVariable>\n\t";
        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";
        fOutput << "<block localId=\"" << (7 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbDPT_Value_Temp_pro\" instanceName=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RT60" << i << "_CT\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (28 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"rValue_IN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (3 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"rSendOnDelta\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables>\n\t";
        fOutput << "<variable formalParameter=\"typDPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inOutVariables>\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"rValue_OUT\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";

        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";

        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"rValue_OUT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";


        //Nytt
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        fOutput << "<connector localId=\"" << (9 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (289 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"xUpdate_PLC\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (10 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"MOVE\">\n\t";
        fOutput << "<position x=\"" << (23 + 16 + *iCfc_x) << "\" y=\"" << (29 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"EN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables />\n\t";
        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ENO\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"Out2\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (11 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 288 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



        fOutput << "<outVariable localId=\"" << (12 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (37 + 8 + *iCfc_x) << "\" y=\"" << (32 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT60" << i << "_CT</expression>\n\t";
        fOutput << "</outVariable>\n\t";

        (*iCfc_Order) += 3;
        (*iCfc_Id) += 13;
        (*iKnx)++;

        if (*iCfc_x >= 40)
        {
            (*iCfc_x) = 2;
            (*iCfc_y) += 19;
            *xSpace = true;
        }
        else
        {
            *iCfc_x += 48;
            *xSpace = false;
        }
    }

    fOutput.close();
    return;
}







void Knx_cfc_Ry(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int& iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int* iCfc_x, bool* xSpace, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (25 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">RY60" << i << "_CV</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";
        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (30 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";

        fOutput << "<expression>" << iMaster << "</expression >\n\t";

        fOutput << "</inVariable>\n\t";
        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << iMaster << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";
        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (31 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";

        fOutput << "<expression>" << *iKnx << "</expression >\n\t";

        fOutput << "</inVariable>\n\t";
        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (37 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>typDPT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (7 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbDPT_Value_AirQuality_pro\" instanceName=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RY60" << i << "_CV\">\n\t";

        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (28 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (18 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (18 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"rValue_IN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (18 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (18 + 3 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (18 + 4 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (18 + 5 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"rSendOnDelta\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 6 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";

        fOutput << "<inOutVariables>\n\t";
        fOutput << "<variable formalParameter=\"typDPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (18 + 6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inOutVariables>\n\t";

        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"rValue_OUT\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (18 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (18 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (18 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"rValue_OUT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";




        //Nytt
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        fOutput << "<connector localId=\"" << (9 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (289 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"xUpdate_PLC\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (10 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"MOVE\">\n\t";
        fOutput << "<position x=\"" << (23 + 16 + *iCfc_x) << "\" y=\"" << (29 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"EN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables />\n\t";
        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ENO\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"Out2\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (11 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 288 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




        fOutput << "<outVariable localId=\"" << (12 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (37 + 8 + *iCfc_x) << "\" y=\"" << (32 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (18 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";

        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RY60" << i << "_CV</expression>\n\t";

        fOutput << "</outVariable>\n\t";

        (*iCfc_Order) += 3;
        (*iCfc_Id) += 13;
        (*iKnx)++;

        if (*iCfc_x >= 40)
        {
            (*iCfc_x) = 2;
            (*iCfc_y) += 19;
            *xSpace = true;
        }
        else
        {
            *iCfc_x += 48;
            *xSpace = false;
        }
    }

    fOutput.close();
    return;
}










///
void Knx_cfc_Lh_OP(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int& iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int* iCfc_x, bool* xSpace, int* iKnxOutputs, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (25 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LH60" << i << "_OP</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (30 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << iMaster << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << iMaster << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (31 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnx << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (2 + *iCfc_x) << "\" y=\"" << (32 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LH60" << i << "_OP</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (2 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LH60" << i << "_OP\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (11 + *iCfc_x) << "\" y=\"" << (35 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>i</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"i\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (11 + *iCfc_x) << "\" y=\"" << (36 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnxOutputs << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"" << *iKnxOutputs << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"EQ\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (33 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables />\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (12 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (37 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>typDPT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"fbDPT_Scaling_pro\" instanceName=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LH60" << i << "_OP\">\n\t";

        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (28 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"rValue_IN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (3 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"rSendOnDelta\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables>\n\t";
        fOutput << "<variable formalParameter=\"typDPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (14 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inOutVariables>\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"rValue_OUT\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        (*iCfc_Order) += 2;
        (*iCfc_Id) += 16;
        (*iKnx)++;
        (*iKnxOutputs)++;

        if (*iCfc_x >= 40)
        {
            (*iCfc_x) = 2;
            (*iCfc_y) += 19;
            *xSpace = true;
        }
        else
        {
            *iCfc_x += 48;
            *xSpace = false;
        }
    }

    fOutput.close();
    return;
}











void Knx_cfc_Lh_CMD(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int& iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int* iCfc_x, bool* xSpace, int* iKnxOutputs, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (25 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LH60" << i << "_CMD</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (30 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << iMaster << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << iMaster << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (31 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnx << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (2 + *iCfc_x) << "\" y=\"" << (32 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LH60" << i << "_CMD</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (2 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LH60" << i << "_CMD\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (6 + *iCfc_x) << "\" y=\"" << (35 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>i</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"i\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (6 + *iCfc_x) << "\" y=\"" << (36 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnxOutputs << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"" << *iKnxOutputs << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"EQ\">\n\t";
        fOutput << "<position x=\"" << (11 + *iCfc_x) << "\" y=\"" << (33 + *iCfc_y) << "\" />\n\t";

        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables />\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (12 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (36 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>typDPT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"fbDPT_Switch_pro\" instanceName=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LH60" << i << "_CMD\">\n\t";

        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (28 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xSwitch_IN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (3 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables>\n\t";
        fOutput << "<variable formalParameter=\"typDPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (14 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inOutVariables>\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"xSwitch_OUT\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        (*iCfc_Order) += 2;
        (*iCfc_Id) += 16;
        (*iKnx)++;
        (*iKnxOutputs)++;

        if (*iCfc_x >= 40)
        {
            (*iCfc_x) = 2;
            (*iCfc_y) += 19;
            *xSpace = true;
        }
        else
        {
            *iCfc_x += 48;
            *xSpace = false;
        }
    }

    fOutput.close();
    return;
}





void Knx_cfc_Lc_OP(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int& iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int* iCfc_x, bool* xSpace, int* iKnxOutputs, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (25 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LC60" << i << "_OP</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (30 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << iMaster << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << iMaster << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (31 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnx << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (2 + *iCfc_x) << "\" y=\"" << (32 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LC60" << i << "_OP</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (2 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LC60" << i << "_OP\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (11 + *iCfc_x) << "\" y=\"" << (35 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>i</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"i\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (11 + *iCfc_x) << "\" y=\"" << (36 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnxOutputs << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"" << *iKnxOutputs << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"EQ\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (33 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables />\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (12 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (37 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>typDPT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"fbDPT_Scaling_pro\" instanceName=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LC60" << i << "_OP\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (28 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"rValue_IN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 3 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 4 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 5 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"rSendOnDelta\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 6 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables>\n\t";
        fOutput << "<variable formalParameter=\"typDPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (14 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inOutVariables>\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"rValue_OUT\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        (*iCfc_Order) += 2;
        (*iCfc_Id) += 16;
        (*iKnx)++;
        (*iKnxOutputs)++;

        if (*iCfc_x >= 40)
        {
            (*iCfc_x) = 2;
            (*iCfc_y) += 19;
            *xSpace = true;
        }
        else
        {
            *iCfc_x += 48;
            *xSpace = false;
        }
    }

    fOutput.close();
    return;
}





void Knx_cfc_Lc_CMD(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int& iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int* iCfc_x, bool* xSpace, int* iKnxOutputs, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (25 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LC60" << i << "_CMD</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (30 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << iMaster << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << iMaster << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (31 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnx << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (2 + *iCfc_x) << "\" y=\"" << (32 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LC60" << i << "_CMD</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (2 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LC60" << i << "_CMD\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (6 + *iCfc_x) << "\" y=\"" << (35 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>i</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"i\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (6 + *iCfc_x) << "\" y=\"" << (36 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnxOutputs << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"" << *iKnxOutputs << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"EQ\">\n\t";
        fOutput << "<position x=\"" << (11 + *iCfc_x) << "\" y=\"" << (33 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables />\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (12 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (36 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>typDPT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"fbDPT_Switch_pro\" instanceName=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LC60" << i << "_CMD\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (28 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xSwitch_IN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 3 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 4 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 5 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables>\n\t";
        fOutput << "<variable formalParameter=\"typDPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (14 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inOutVariables>\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"xSwitch_OUT\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        (*iCfc_Order) += 2;
        (*iCfc_Id) += 16;
        (*iKnx)++;
        (*iKnxOutputs)++;

        if (*iCfc_x >= 40)
        {
            (*iCfc_x) = 2;
            (*iCfc_y) += 19;
            *xSpace = true;
        }
        else
        {
            *iCfc_x += 48;
            *xSpace = false;
        }
    }

    fOutput.close();
    return;
}












void Knx_cfc_Sp(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int& iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int* iCfc_x, bool* xSpace, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (*iCfc_y + 25) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">RT60" << i << "_SP</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (*iCfc_y + 30) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << iMaster << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (*iCfc_y + 275) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << iMaster << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (*iCfc_y + 31) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnx << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (*iCfc_y + 275) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (1 + *iCfc_x) << "\" y=\"" << (*iCfc_y + 32) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";

        if (i == 1)
            fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT60" << i << "_SP_D</expression>\n\t";
        else
            fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT60" << i << "_SP</expression>\n\t";

        fOutput << "</inVariable>\n\t";


        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (1 + *iCfc_x) << "\" y=\"" << (*iCfc_y + 275) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";

        if (i == 1)
            fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT60" << i << "_SP_D\" />\n\t";
        else
            fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT60" << i << "_SP\" />\n\t";

        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";


        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\" negated=\"true\">\n\t";
        fOutput << "<position x=\"" << (1 + *iCfc_x) << "\" y=\"" << (*iCfc_y + 33) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RB601_HVAC</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (1 + *iCfc_x) << "\" y=\"" << (*iCfc_y + 275) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RB601_HVAC\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (*iCfc_y + 37) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>typDPT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (*iCfc_y + 275) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbDPT_Value_Temp_pro\" instanceName=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RT60" << i << "_SP\">\n\t";

        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (*iCfc_y + 28) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (*iCfc_y + 0) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (*iCfc_y + 1) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"rValue_IN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (*iCfc_y + 2) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (*iCfc_y + 3) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (*iCfc_y + 4) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (*iCfc_y + 5) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"rSendOnDelta\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (*iCfc_y + 6) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables>\n\t";
        fOutput << "<variable formalParameter=\"typDPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (*iCfc_y + 7) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inOutVariables>\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"rValue_OUT\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (*iCfc_y + 0) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (*iCfc_y + 1) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (*iCfc_y + 2) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";


        (*iCfc_Order) += 1;
        (*iCfc_Id) += 12;
        (*iKnx)++;

        if (*iCfc_x >= 40)
        {
            (*iCfc_x) = 2;
            (*iCfc_y) += 19;
            *xSpace = true;
        }
        else
        {
            *iCfc_x += 48;
            *xSpace = false;
        }
    }

    fOutput.close();
    return;
}






void Knx_cfc_Sp_Fb(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int& iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int* iCfc_x, bool* xSpace, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (25 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">RT60" << i << "_SP Feedback</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (30 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << iMaster << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (7 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << iMaster << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (31 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnx << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (7 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (37 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>typDPT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (7 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (7 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbDPT_Value_Temp_pro\" instanceName=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RT60" << i << "_SP_FB\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (28 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"rValue_IN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (3 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"rSendOnDelta\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables>\n\t";
        fOutput << "<variable formalParameter=\"typDPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inOutVariables>\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"rValue_OUT\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"rValue_OUT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";




        //Nytt
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        fOutput << "<connector localId=\"" << (9 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (289 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"xUpdate_PLC\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (10 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"MOVE\">\n\t";
        fOutput << "<position x=\"" << (23 + 16 + *iCfc_x) << "\" y=\"" << (29 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"EN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables />\n\t";
        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ENO\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"Out2\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (11 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 288 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




        fOutput << "<outVariable localId=\"" << (12 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (37 + 8 + *iCfc_x) << "\" y=\"" << (32 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT60" << i << "_SP_IN</expression>\n\t";
        fOutput << "</outVariable>\n\t";


        (*iCfc_Order) += 3;
        (*iCfc_Id) += 13;
        (*iKnx)++;

        if (*iCfc_x >= 40)
        {
            (*iCfc_x) = 2;
            (*iCfc_y) += 19;
            *xSpace = true;
        }
        else
        {
            *iCfc_x += 48;
            *xSpace = false;
        }
    }
    fOutput.close();
    return;
}









void Knx_cfc_Lu_V(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int& iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int* iCfc_x, bool* xSpace, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (25 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LU60" << i << "_V</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (1 + 29 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << iMaster << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 454 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << iMaster << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (1 + 30 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnx << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 454 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (1 + 35 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>typDPT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 454 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (7 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbDPT_Switch_pro\" instanceName=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LU60" << i << "_V\">\n\t";

        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (1 + 27 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xSwitch_IN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 3 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 4 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 5 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables>\n\t";
        fOutput << "<variable formalParameter=\"typDPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inOutVariables>\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"xSwitch_OUT\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 288 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"xSwitch_OUT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";




        //Nytt
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        fOutput << "<connector localId=\"" << (9 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (289 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"xUpdate_PLC\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (10 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"MOVE\">\n\t";
        fOutput << "<position x=\"" << (23 + 16 + *iCfc_x) << "\" y=\"" << (29 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"EN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables />\n\t";
        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ENO\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"Out2\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (11 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 288 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




        fOutput << "<outVariable localId=\"" << (12 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (37 + 8 + *iCfc_x) << "\" y=\"" << (32 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";

        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LU60" << i << "_V</expression>\n\t";

        fOutput << "</outVariable>\n\t";

        (*iCfc_Id) += 13;
        (*iCfc_Order) += 3;
        (*iKnx)++;

        if (*iCfc_x >= 40)
        {
            (*iCfc_x) = 2;
            (*iCfc_y) += 18;
            *xSpace = true;
        }
        else
        {
            *iCfc_x += 48;
            *xSpace = false;
        }
    }

    fOutput.close();
    return;
}









void Knx_cfc_Lu_Al(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int& iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int* iCfc_x, bool* xSpace, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (25 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LU60" << i << "_AL</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (1 + 29 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << iMaster << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 454 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << iMaster << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (1 + 30 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnx << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 454 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (1 + 35 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>typDPT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 454 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (7 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbDPT_Switch_pro\" instanceName=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LU60" << i << "_AL\">\n\t";

        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (1 + 27 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xSwitch_IN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 3 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 4 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 5 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables>\n\t";
        fOutput << "<variable formalParameter=\"typDPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inOutVariables>\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"xSwitch_OUT\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 288 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"xSwitch_OUT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";




        //Nytt
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        fOutput << "<connector localId=\"" << (9 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (289 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"xUpdate_PLC\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (10 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"MOVE\">\n\t";
        fOutput << "<position x=\"" << (23 + 16 + *iCfc_x) << "\" y=\"" << (29 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"EN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables />\n\t";
        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ENO\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"Out2\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (11 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 288 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




        fOutput << "<outVariable localId=\"" << (12 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (37 + 8 + *iCfc_x) << "\" y=\"" << (32 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LU60" << i << "_AL</expression>\n\t";
        fOutput << "</outVariable>\n\t";

        (*iCfc_Id) += 13;
        (*iCfc_Order) += 3;
        (*iKnx)++;

        if (*iCfc_x >= 40)
        {
            (*iCfc_x) = 2;
            (*iCfc_y) += 18;
            *xSpace = true;
        }
        else
        {
            *iCfc_x += 48;
            *xSpace = false;
        }
    }

    fOutput.close();
    return;
}





void Knx_cfc_Lu_CMD(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int& iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int* iCfc_x, bool* xSpace, int* iKnxOutputs, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (25 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LU60" << i << "_CMD</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (30 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << iMaster << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << iMaster << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (31 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnx << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (2 + *iCfc_x) << "\" y=\"" << (32 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LU60" << i << "_CMD</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (2 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LU60" << i << "_CMD\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (6 + *iCfc_x) << "\" y=\"" << (35 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>i</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"i\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (6 + *iCfc_x) << "\" y=\"" << (36 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnxOutputs << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"" << *iKnxOutputs << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"EQ\">\n\t";
        fOutput << "<position x=\"" << (11 + *iCfc_x) << "\" y=\"" << (33 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables />\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (12 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (36 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>typDPT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"fbDPT_Switch_pro\" instanceName=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LU60" << i << "_CMD\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (28 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xSwitch_IN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 3 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 4 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 5 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables>\n\t";
        fOutput << "<variable formalParameter=\"typDPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (14 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inOutVariables>\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"xSwitch_OUT\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        (*iCfc_Order) += 2;
        (*iCfc_Id) += 16;
        (*iKnx)++;
        (*iKnxOutputs)++;

        if (*iCfc_x >= 40)
        {
            (*iCfc_x) = 2;
            (*iCfc_y) += 19;
            *xSpace = true;
        }
        else
        {
            *iCfc_x += 48;
            *xSpace = false;
        }
    }

    fOutput.close();
    return;
}






void Knx_cfc_Opm_Out(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int& iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int* iCfc_x, bool* xSpace, int* iKnxOutputs, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (25 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">OPM_00" << i << "</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (30 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << iMaster << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << iMaster << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (31 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnx << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (2 + *iCfc_x) << "\" y=\"" << (32 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".OPM_00" << i << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (2 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".OPM_00" << i << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (11 + *iCfc_x) << "\" y=\"" << (35 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>i</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"i\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (11 + *iCfc_x) << "\" y=\"" << (36 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << *iKnxOutputs << "</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"" << *iKnxOutputs << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"EQ\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (33 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"In1\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables />\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"Out1\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (12 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (15 + *iCfc_x) << "\" y=\"" << (37 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>typDPT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (9 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"fbDPT_1_BYTE\" instanceName=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_OPM_00" << i << "\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (28 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"bIN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 3 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 4 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 5 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables>\n\t";
        fOutput << "<variable formalParameter=\"typDPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 6 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (14 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inOutVariables>\n\t";

        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (16 + 2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        (*iCfc_Order) += 2;
        (*iCfc_Id) += 16;
        (*iKnx)++;
        (*iKnxOutputs)++;

        if (*iCfc_x >= 40)
        {
            (*iCfc_x) = 2;
            (*iCfc_y) += 18;
            *xSpace = true;
        }
        else
        {
            *iCfc_x += 48;
            *xSpace = false;
        }
    }

    fOutput.close();
    return;
}














void Knx_cfc_Rh_Cv(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int& iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int* iCfc_x, bool* xSpace, int& iAntall)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (25 + *iCfc_y) << "\" />\n\t";
        fOutput << "<content>\n\t";
        fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">RH60" << i << "_CV</xhtml>\n\t";
        fOutput << "</content>\n\t";
        fOutput << "</comment>\n\t";

        fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (30 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";

        fOutput << "<expression>" << iMaster << "</expression>\n\t";

        fOutput << "</inVariable>\n\t";
        fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << iMaster << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";
        fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (18 + *iCfc_x) << "\" y=\"" << (31 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";

        fOutput << "<expression>" << *iKnx << "</expression>\n\t";

        fOutput << "</inVariable>\n\t";
        fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";
        fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (16 + *iCfc_x) << "\" y=\"" << (37 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";

        fOutput << "<expression>typDPT</expression>\n\t";

        fOutput << "</inVariable>\n\t";
        fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";
        fOutput << "<block localId=\"" << (7 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"FbDPT_Value_Humidity_pro\" instanceName=\"M" << iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RH60" << i << "_CV\">\n\t";
        fOutput << "<position x=\"" << (23 + *iCfc_x) << "\" y=\"" << (28 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";
        fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"rValue_IN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (3 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (4 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (5 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"rSendOnDelta\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (6 + *iCfc_y) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables>\n\t";
        fOutput << "<variable formalParameter=\"typDPT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (7 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</inOutVariables>\n\t";
        fOutput << "<outputVariables>\n\t";
        fOutput << "<variable formalParameter=\"rValue_OUT\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (1 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (2 + *iCfc_y) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";

        fOutput << "<CallType xmlns=\"\">functionblock</CallType>\n\t";

        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5 + *iCfc_x) << "\" y=\"" << (275 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"rValue_OUT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";


        //Nytt
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        fOutput << "<connector localId=\"" << (9 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (289 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"xUpdate_PLC\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<block localId=\"" << (10 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"MOVE\">\n\t";
        fOutput << "<position x=\"" << (23 + 16 + *iCfc_x) << "\" y=\"" << (29 + *iCfc_y) << "\" />\n\t";
        fOutput << "<inputVariables>\n\t";

        fOutput << "<variable formalParameter=\"EN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"In2\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</inputVariables>\n\t";
        fOutput << "<inOutVariables />\n\t";
        fOutput << "<outputVariables>\n\t";

        fOutput << "<variable formalParameter=\"ENO\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"Out2\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"0\" y=\"1\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "</outputVariables>\n\t";
        fOutput << "<addData>\n\t";
        fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfccalltype\" handleUnknown=\"implementation\">\n\t";
        fOutput << "<CallType xmlns=\"\">operator</CallType>\n\t";
        fOutput << "</data>\n\t";
        fOutput << "</addData>\n\t";
        fOutput << "</block>\n\t";

        fOutput << "<connector localId=\"" << (11 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (05 + *iCfc_x) << "\" y=\"" << (1 + 288 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



        fOutput << "<outVariable localId=\"" << (12 + *iCfc_Id) << "\" executionOrderId=\"" << (2 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (37 + 8 + *iCfc_x) << "\" y=\"" << (32 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0 + *iCfc_x) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT60" << i << "_CT</expression>\n\t";
        fOutput << "</outVariable>\n\t";

        (*iCfc_Order) += 3;
        (*iCfc_Id) += 13;
        (*iKnx)++;

        if (*iCfc_x >= 40)
        {
            (*iCfc_x) = 2;
            (*iCfc_y) += 19;
            *xSpace = true;
        }
        else
        {
            *iCfc_x += 48;
            *xSpace = false;
        }
    }

    fOutput.close();
    return;
}











//Nytt
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Romstyring
//Lokal variabler
void Knx_var_Romstyring_Fb(std::string& sPath, std::string& sRom, std::string& sRomtype)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<variable name=\"Rom_" << sRom << "\">\n\t";
    fOutput << "<type>\n\t";
    fOutput << "<derived name=\"fbRomtype_" << sRomtype << "\" />\n\t";
    fOutput << "</type>\n\t";
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sRom << "</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n\t";

    fOutput.close();
    return;
}


//comment
void Knx_cfc_Fb_Comment(std::string& sPath, std::string& sRom, int* iCfc_Id, int* iCfc_y)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<comment localId=\"" << (+*iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (26) << "\" y=\"" << (25 + *iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Rom " << sRom << "</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    (*iCfc_Id)++;


    fOutput.close();
    return;
}





//Input variabler
void Knx_cfc_In_Hvac(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {

        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (4) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RB60" << i << "_HVAC</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RB60" << i << "_HVAC\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";


        (*iInOut)++;
        (*iCfc_Id) += 2;
    }

    fOutput.close();
    return;
}

void Knx_cfc_In_Rt(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut, std::string& sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    //CT
    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT60" << i << "_CT</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT60" << i << "_CT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        (*iInOut)++;
        (*iCfc_Id) += 2;

        if (i > 1 && sFb != "1")
        {
            fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
            fOutput << "<position x=\"" << (5) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
            fOutput << "<connectionPointOut>\n\t";
            fOutput << "<expression />\n\t";
            fOutput << "</connectionPointOut>\n\t";
            fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT60" << i << "_SP</expression>\n\t";
            fOutput << "</inVariable>\n\t";

            fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
            fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT60" << i << "_SP\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</connector>\n\t";

            (*iInOut)++;
            (*iCfc_Id) += 2;
        }
    }

    if (sFb == "1" && iAntall > 1)
    {

        //SP Dag
        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (4) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT600_SP_D</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT600_SP_D\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        (*iInOut)++;
        (*iCfc_Id) += 2;

        //SP Standby
        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (4) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT600_SP_S</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT600_SP_S\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        (*iInOut)++;
        (*iCfc_Id) += 2;

        //SP Natt
        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (4) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT600_SP_N</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT600_SP_N\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        (*iInOut)++;
        (*iCfc_Id) += 2;

        //SP Frost
        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (4) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT600_SP_F</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT600_SP_F\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        (*iInOut)++;
        (*iCfc_Id) += 2;
    }
    else
    {
        //SP Dag
        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (4) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT601_SP_D</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT601_SP_D\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        (*iInOut)++;
        (*iCfc_Id) += 2;

        //SP Standby
        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (4) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT601_SP_S</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT601_SP_S\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        (*iInOut)++;
        (*iCfc_Id) += 2;

        //SP Natt
        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (4) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT601_SP_N</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT601_SP_N\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        (*iInOut)++;
        (*iCfc_Id) += 2;

        //SP Frost
        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (4) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT601_SP_F</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT601_SP_F\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        (*iInOut)++;
        (*iCfc_Id) += 2;
    }

    //OPM
    fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (7) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".OPM</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".OPM\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    (*iInOut)++;
    (*iCfc_Id) += 2;


    fOutput.close();
    return;
}

void Knx_cfc_In_Ry(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut, std::string& sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RY60" << i << "_CV</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RY60" << i << "_CV\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";


        (*iInOut)++;
        (*iCfc_Id) += 2;
    }

    if (sFb == "1" && iAntall > 1)
    {
        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RY600_SP</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RY600_SP\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (2 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (4) << "\" y=\"" << (31 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RY600_MAN</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (3 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RY600_MAN\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";
    }
    else
    {
        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RY601_SP</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RY601_SP\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<inVariable localId=\"" << (2 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (4) << "\" y=\"" << (31 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RY601_MAN</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (3 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RY601_MAN\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";
    }


    (*iInOut) += 2;
    (*iCfc_Id) += 4;

    fOutput.close();
    return;
}

//Lh Man
void Knx_cfc_In_Lh(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (4) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LH601_MAN</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LH601_MAN\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    (*iInOut)++;
    (*iCfc_Id) += 2;

    fOutput.close();
    return;
}

//Lc
void Knx_cfc_In_Lc(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (5) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LC601_SP</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LC601_SP\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";


    fOutput << "<inVariable localId=\"" << (2 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (4) << "\" y=\"" << (31 + *iCfc_y + *iInOut) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LC601_MAN</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (3 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LC601_MAN\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    (*iInOut) += 2;
    (*iCfc_Id) += 4;

    fOutput.close();
    return;
}

//Sp
void Knx_cfc_In_Sp(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (4) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT60" << i << "_SP_IN</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT60" << i << "_SP_IN\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        (*iInOut)++;
        (*iCfc_Id) += 2;
    }

    fOutput.close();
    return;
}

void Knx_cfc_In_Lu_V(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LU60" << i << "_V</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LU60" << i << "_V\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";


        (*iInOut)++;
        (*iCfc_Id) += 2;
    }

    fOutput.close();
    return;
}

void Knx_cfc_In_Rh_Cv(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<inVariable localId=\"" << (0 + *iCfc_Id) << "\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (30 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RH60" << i << "_CV</expression>\n\t";
        fOutput << "</inVariable>\n\t";

        fOutput << "<connector localId=\"" << (1 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (0) << "\" y=\"" << (0 + *iCfc_y) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RH60" << i << "_V\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";


        (*iInOut)++;
        (*iCfc_Id) += 2;
    }

    fOutput.close();
    return;
}






//Funksjonsblokk inputs
void Knx_cfc_In_Fb_Hvac(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int& iInOut, int* iFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable formalParameter=\"RB60" << i << "_HVAC\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;
    }

    fOutput.close();
    return;
}

void Knx_cfc_In_Fb_Rt(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int& iInOut, int* iFb, std::string& sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable formalParameter=\"RT60" << i << "_CT\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;

        if (i > 1 && sFb != "1")
        {
            fOutput << "<variable formalParameter=\"RT60" << i << "_SP\">\n\t";
            fOutput << "<connectionPointIn>\n\t";
            fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
            fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
            fOutput << "</connectionPointIn>\n\t";
            fOutput << "</variable>\n\t";

            (*iFb)++;
        }
    }

    if (sFb == "1" && iAntall > 1)
    {
        fOutput << "<variable formalParameter=\"RT600_SP_D\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;

        fOutput << "<variable formalParameter=\"RT600_SP_S\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;

        fOutput << "<variable formalParameter=\"RT600_SP_N\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;

        fOutput << "<variable formalParameter=\"RT600_SP_F\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;
    }
    else
    {
        fOutput << "<variable formalParameter=\"RT601_SP_D\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;

        fOutput << "<variable formalParameter=\"RT601_SP_S\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;

        fOutput << "<variable formalParameter=\"RT601_SP_N\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;

        fOutput << "<variable formalParameter=\"RT601_SP_F\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;
    }

    fOutput << "<variable formalParameter=\"OPM\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    (*iFb)++;


    fOutput.close();
    return;
}

void Knx_cfc_In_Fb_Ry(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int& iInOut, int* iFb, std::string& sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable formalParameter=\"RY60" << i << "_CV\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;
    }

    if (sFb == "1" && iAntall > 1)
    {
        fOutput << "<variable formalParameter=\"RY600_SP\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"RY600_MAN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (17 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb) += 2;
    }
    else
    {
        fOutput << "<variable formalParameter=\"RY601_SP\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"RY601_MAN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (17 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb) += 2;
    }

    fOutput.close();
    return;
}

//Lh Man
void Knx_cfc_In_Fb_Lh(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int& iInOut, int* iFb, std::string& sFb, int iAntallT)
{
    std::ofstream fOutput(sPath, std::ios::app);

    if (sFb == "1" && iAntallT > 1)
    {
        fOutput << "<variable formalParameter=\"LH600_MAN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
    }
    else
    {
        fOutput << "<variable formalParameter=\"LH601_MAN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";
    }

    (*iFb)++;

    fOutput.close();
    return;
}

//Lc
void Knx_cfc_In_Fb_Lc(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int& iInOut, int* iFb, std::string& sFb, int iAntallT)
{
    std::ofstream fOutput(sPath, std::ios::app);

    if (sFb == "1" && iAntallT > 1)
    {
        fOutput << "<variable formalParameter=\"LC600_SP\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;

        fOutput << "<variable formalParameter=\"LC600_MAN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;
    }
    else
    {
        fOutput << "<variable formalParameter=\"LC601_SP\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;

        fOutput << "<variable formalParameter=\"LC601_MAN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;
    }

    fOutput.close();
    return;
}

void Knx_cfc_In_Fb_Sp(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int& iInOut, int* iFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable formalParameter=\"RT60" << i << "_SP_IN\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;
    }

    fOutput.close();
    return;
}

void Knx_cfc_In_Fb_Lu_V(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int& iInOut, int* iFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable formalParameter=\"LU60" << i << "_V\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;
    }

    fOutput.close();
    return;
}


void Knx_cfc_In_Fb_Rh_Cv(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int& iInOut, int* iFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable formalParameter=\"RH60" << i << "_V\">\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + *iFb + *iCfc_y) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - (iInOut * 2) + (*iFb * 2)) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</variable>\n\t";

        (*iFb)++;
    }

    fOutput.close();
    return;
}




//Funksjonsblokk Outputs
void Knx_cfc_Fb_Out_Hvac(std::string& sPath, int* iCfc_y, int& iAntall, int* iInOut)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<variable formalParameter=\"RB600_HVAC\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    (*iInOut)++;

    fOutput.close();
    return;
}
void Knx_cfc_Fb_Out_Rt(std::string& sPath, int* iCfc_y, int& iAntall, int* iInOut, std::string& sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<variable formalParameter=\"OPM_CV\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    (*iInOut)++;

    if (sFb != "1" || iAntall < 2)
    {
        fOutput << "<variable formalParameter=\"RT601_CS\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        (*iInOut)++;
    }
    else
    {
        fOutput << "<variable formalParameter=\"RT600_CT\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"RT600_CS\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (17 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        (*iInOut) += 2;
    }


    fOutput.close();
    return;
}

void Knx_cfc_Fb_Out_Ry_Op(std::string& sPath, int* iCfc_y, int& iAntall, int* iInOut, std::string sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    if (sFb != "1" || iAntall < 2)
    {
        fOutput << "<variable formalParameter=\"RY601_OP\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        (*iInOut)++;
    }
    else
    {
        fOutput << "<variable formalParameter=\"RY600_CV\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        fOutput << "<variable formalParameter=\"RY600_OP\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (17 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";
        (*iInOut) += 2;
    }


    fOutput.close();
    return;
}


void Knx_cfc_Fb_Out_Lh_Op(std::string& sPath, int* iCfc_y, int& iAntall, int* iInOut)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable formalParameter=\"LH60" << i << "_OP\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        (*iInOut)++;
    }

    (*iInOut)++;

    fOutput.close();
    return;
}

void Knx_cfc_Fb_Out_Lh_Cmd(std::string& sPath, int* iCfc_y, int& iAntall, int* iInOut)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable formalParameter=\"LH60" << i << "_CMD\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        (*iInOut)++;
    }

    fOutput.close();
    return;
}


void Knx_cfc_Fb_Out_Lc_Op(std::string& sPath, int* iCfc_y, int& iAntall, int* iInOut)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable formalParameter=\"LC60" << i << "_OP\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        (*iInOut)++;
    }

    fOutput.close();
    return;
}

void Knx_cfc_Fb_Out_Lc_Cmd(std::string& sPath, int* iCfc_y, int& iAntall, int* iInOut)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable formalParameter=\"LC60" << i << "_CMD\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        (*iInOut)++;
    }

    fOutput.close();
    return;
}

void Knx_cfc_Fb_Out_Lu_Cmd(std::string& sPath, int* iCfc_y, int& iAntall, int* iInOut)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable formalParameter=\"LU60" << i << "_CMD\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        (*iInOut)++;
    }

    fOutput.close();
    return;
}

void Knx_cfc_Fb_Out_Opm_Out(std::string& sPath, int* iCfc_y, int& iAntall, int* iInOut)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<variable formalParameter=\"OPM_00" << i << "\">\n\t";
        fOutput << "<connectionPointOut>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (16 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<expression />\n\t";
        fOutput << "</connectionPointOut>\n\t";
        fOutput << "</variable>\n\t";

        (*iInOut)++;
    }

    fOutput.close();
    return;
}





//Outputs
void Knx_cfc_Out_Hvac(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut, int& iFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<connector localId=\"" << (0 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (5) << "\" y=\"" << (289 + *iCfc_y + *iInOut) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (*iCfc_Id - 1 - (*iInOut * 2)) << "\" formalParameter=\"RB600_HVAC\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"" << (40) << "\" y=\"" << (1 + 29 + *iCfc_y + *iInOut) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RB600_HVAC</expression>\n\t";
    fOutput << "</outVariable>\n\t";

    (*iInOut)++;
    (*iCfc_Order) += 1;
    (*iCfc_Id) += 2;

    fOutput.close();
    return;
}


void Knx_cfc_Out_Rt(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut, int& iFb, std::string& sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<connector localId=\"" << (0 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (5) << "\" y=\"" << (289 + *iCfc_y + *iInOut) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (*iCfc_Id - 1 - (*iInOut * 2)) << "\" formalParameter=\"OPM_CV\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"" << (40) << "\" y=\"" << (1 + 29 + *iCfc_y + *iInOut) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".OPM_CV</expression>\n\t";
    fOutput << "</outVariable>\n\t";

    (*iInOut)++;
    (*iCfc_Order) += 1;
    (*iCfc_Id) += 2;

    if (sFb != "1" || iAntall < 2)
    {
        fOutput << "<connector localId=\"" << (0 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (289 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - 1 - (*iInOut * 2)) << "\" formalParameter=\"RT601_CS\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (40) << "\" y=\"" << (1 + 29 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT601_CS</expression>\n\t";
        fOutput << "</outVariable>\n\t";
    }
    else
    {
        fOutput << "<connector localId=\"" << (0 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (289 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - 1 - (*iInOut * 2)) << "\" formalParameter=\"RT600_CT\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (40) << "\" y=\"" << (1 + 29 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT600_CT</expression>\n\t";
        fOutput << "</outVariable>\n\t";

        (*iInOut)++;
        (*iCfc_Order) += 1;
        (*iCfc_Id) += 2;

        fOutput << "<connector localId=\"" << (0 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (289 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - 1 - (*iInOut * 2)) << "\" formalParameter=\"RT600_CS\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (40) << "\" y=\"" << (1 + 29 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT600_CS</expression>\n\t";
        fOutput << "</outVariable>\n\t";
    }

    (*iInOut)++;
    (*iCfc_Order) += 1;
    (*iCfc_Id) += 2;

    fOutput.close();
    return;
}

void Knx_cfc_Out_Ry_Op(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut, int& iFb, std::string sFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    if (sFb == "1" && iAntall > 1)
    {
        fOutput << "<connector localId=\"" << (0 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (289 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - 1 - (*iInOut * 2)) << "\" formalParameter=\"RY600_CV\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (40) << "\" y=\"" << (1 + 29 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RY600_CV</expression>\n\t";
        fOutput << "</outVariable>\n\t";

        (*iInOut)++;
        (*iCfc_Order) += 1;
        (*iCfc_Id) += 2;

        fOutput << "<connector localId=\"" << (0 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (289 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - 1 - (*iInOut * 2)) << "\" formalParameter=\"RY600_OP\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (40) << "\" y=\"" << (1 + 29 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RY600_OP</expression>\n\t";
        fOutput << "</outVariable>\n\t";
    }
    else
    {
        fOutput << "<connector localId=\"" << (0 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (289 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - 1 - (*iInOut * 2)) << "\" formalParameter=\"RY601_OP\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (40) << "\" y=\"" << (1 + 29 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RY601_OP</expression>\n\t";
        fOutput << "</outVariable>\n\t";
    }



    (*iInOut)++;
    (*iCfc_Order) += 1;
    (*iCfc_Id) += 2;

    fOutput.close();
    return;
}


void Knx_cfc_Out_Lh_Op(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut, int& iFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<connector localId=\"" << (0 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (289 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - 1 - (*iInOut * 2)) << "\" formalParameter=\"LH60" << i << "_OP\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (40) << "\" y=\"" << (1 + 29 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LH60" << i << "_OP</expression>\n\t";
        fOutput << "</outVariable>\n\t";

        (*iInOut)++;
        (*iCfc_Order) += 1;
        (*iCfc_Id) += 2;
    }

    fOutput.close();
    return;
}

void Knx_cfc_Out_Lh_Cmd(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut, int& iFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<connector localId=\"" << (0 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (289 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - 1 - (*iInOut * 2)) << "\" formalParameter=\"LH60" << i << "_CMD\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (40) << "\" y=\"" << (1 + 29 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LH60" << i << "_CMD</expression>\n\t";
        fOutput << "</outVariable>\n\t";

        (*iInOut)++;
        (*iCfc_Order) += 1;
        (*iCfc_Id) += 2;
    }

    fOutput.close();
    return;
}

void Knx_cfc_Out_Lc_Op(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut, int& iFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<connector localId=\"" << (0 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (289 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - 1 - (*iInOut * 2)) << "\" formalParameter=\"LC60" << i << "_OP\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (40) << "\" y=\"" << (1 + 29 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LC60" << i << "_OP</expression>\n\t";
        fOutput << "</outVariable>\n\t";

        (*iInOut)++;
        (*iCfc_Order) += 1;
        (*iCfc_Id) += 2;
    }

    fOutput.close();
    return;
}

void Knx_cfc_Out_Lc_Cmd(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut, int& iFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<connector localId=\"" << (0 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (289 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - 1 - (*iInOut * 2)) << "\" formalParameter=\"LC60" << i << "_CMD\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (40) << "\" y=\"" << (1 + 29 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LC60" << i << "_CMD</expression>\n\t";
        fOutput << "</outVariable>\n\t";

        (*iInOut)++;
        (*iCfc_Order) += 1;
        (*iCfc_Id) += 2;
    }

    fOutput.close();
    return;
}

void Knx_cfc_Out_Lu_Cmd(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut, int& iFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<connector localId=\"" << (0 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (289 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - 1 - (*iInOut * 2)) << "\" formalParameter=\"LU60" << i << "_CMD\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (40) << "\" y=\"" << (1 + 29 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LU60" << i << "_CMD</expression>\n\t";
        fOutput << "</outVariable>\n\t";

        (*iInOut)++;
        (*iCfc_Order) += 1;
        (*iCfc_Id) += 2;
    }

    fOutput.close();
    return;
}

void Knx_cfc_Out_Opm_Out(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iCfc_Order, int* iCfc_Id, int* iCfc_y, int& iAntall, int* iInOut, int& iFb)
{
    std::ofstream fOutput(sPath, std::ios::app);

    for (int i = 1; i <= iAntall; i++)
    {
        fOutput << "<connector localId=\"" << (0 + *iCfc_Id) << "\" name=\"\">\n\t";
        fOutput << "<position x=\"" << (5) << "\" y=\"" << (289 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<connection refLocalId=\"" << (*iCfc_Id - 1 - (*iInOut * 2)) << "\" formalParameter=\"OPM_00" << i << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "</connector>\n\t";

        fOutput << "<outVariable localId=\"" << (1 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\">\n\t";
        fOutput << "<position x=\"" << (40) << "\" y=\"" << (1 + 29 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connectionPointIn>\n\t";
        fOutput << "<relPosition x=\"" << (0) << "\" y=\"" << (1 + 0 + *iCfc_y + *iInOut) << "\" />\n\t";
        fOutput << "<connection refLocalId=\"" << (0 + *iCfc_Id) << "\" />\n\t";
        fOutput << "</connectionPointIn>\n\t";
        fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".OPM_00" << i << "</expression>\n\t";
        fOutput << "</outVariable>\n\t";

        (*iInOut)++;
        (*iCfc_Order) += 1;
        (*iCfc_Id) += 2;
    }

    fOutput.close();
    return;
}


#endif