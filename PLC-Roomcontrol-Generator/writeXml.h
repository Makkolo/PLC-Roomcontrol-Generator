#pragma once
#ifndef writeXml
#define writeXml
#include <iostream>
#include <fstream>
#include <windows.h>
#include "roomcontrolXmlLib.h"
#include "mortLib.h"







void WriteXML_KNX(std::string sPath, bool(&bUsed)[1000], std::string& sGVL, std::string(&sRom)[1000], std::string(&sRomtype)[1000], std::string(&sKommentar)[1000], std::string& sAdresseFormat, int const& iMax)
{
    //Variabel deklarering
    int iMaster = 1, iKnx = 1, iKnxOutputs = -1, iCfc_id = 0, iCfc_Order = 0, iCfc_y = 0, iCfc_x = 0, iLast1 = 0, iLast2 = 0;
    std::string sPreset = "";
    bool xComment = true, xSpace = false;


    sPath = sPath + "AutGenImport.xml";

    //Kopierer XML filens adresse, til utklippstavle
    const char* output = sPath.c_str();
    const size_t len = strlen(output) + 1;
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(hMem), output, len);
    GlobalUnlock(hMem);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMem);
    CloseClipboard();

    //Lager xml filen
    std::ofstream fOutput(sPath);

    if (fOutput.is_open() == false)
    {
        std::cout << "Error: cant open outputfile.\nLine: 908 mdhl.h";
        Sleep(10000);
        abort();
    }
    //Skriver begynnelse av XML filen, slik e!cockpit gjør under export.
    fOutput << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
    fOutput << "<project xmlns=\"http://www.plcopen.org/xml/tc6_0200\">\n\t";
    fOutput << "<fileHeader companyName=\"WAGO\" productName=\"e!COCKPIT\" productVersion=\"e!COCKPIT\" creationDateTime=\"2021-01-18T14:20:23.2110188\" />\n\t";
    fOutput << "<contentHeader name=\"Adressering.ecp\" modificationDateTime=\"2021-01-18T11:51:27.6823754\">\n\t\t";
    fOutput << "<coordinateInfo>\n" + Tabs(3);
    fOutput << "<fbd>\n" + Tabs(4);
    fOutput << "<scaling x=\"1\" y=\"1\" />\n" + Tabs(3);
    fOutput << "</fbd>\n" + Tabs(3);
    fOutput << "<ld>\n" + Tabs(4);
    fOutput << "<scaling x=\"1\" y=\"1\" />\n" + Tabs(3);
    fOutput << "</ld>\n" + Tabs(3);
    fOutput << "<sfc>\n" + Tabs(4);
    fOutput << "<scaling x=\"1\" y=\"1\" />\n" + Tabs(3);
    fOutput << "</sfc>\n\t\t";
    fOutput << "</coordinateInfo>\n\t\t";
    fOutput << "<addData>\n" + Tabs(3);
    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/projectinformation\" handleUnknown=\"implementation\">\n" + Tabs(4);
    fOutput << "<ProjectInformation />\n" + Tabs(3);
    fOutput << "</data>\n\t\t";
    fOutput << "</addData>\n\t";
    fOutput << "</contentHeader>\n\t";
    fOutput << "<types>\n\t\t";
    fOutput << "<dataTypes />\n\t\t";
    fOutput << "<pous>\n\t\t";

    fOutput << "<pou name=\"PRG_563_KNX\" pouType=\"program\">\n" + Tabs(3);
    fOutput << "<interface>\n" + Tabs(4);
    fOutput << "<localVars>\n" + Tabs(5);

    //Local Var

    fOutput << "<variable name=\"i\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<INT />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(6);
    fOutput << "<initialValue>\n" + Tabs(7);
    fOutput << "<simpleValue value=\"0\" />\n" + Tabs(6);
    fOutput << "</initialValue>\n" + Tabs(6);
    fOutput << "<documentation>\n" + Tabs(7);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">Felles</xhtml>\n" + Tabs(6);
    fOutput << "</documentation>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"Interval\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<derived name=\"OSCAT_BASIC.CLK_PRG\" />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput << "<variable name=\"typDPT\">\n" + Tabs(6);
    fOutput << "<type>\n" + Tabs(7);
    fOutput << "<derived name=\"typDPT\" />\n" + Tabs(6);
    fOutput << "</type>\n" + Tabs(5);
    fOutput << "</variable>\n" + Tabs(5);

    fOutput.close();

    //Skriver lokalvariabler
    for (int i = 0; i < iMax; i++)
    {
        if (bUsed[i])
        {
            for (int j = 0; j < 10; j++)
            {
                xComment = true;
                if (j < sRomtype[i].size() && sRomtype[i].substr(j, 1) == "1")
                {
                    switch (j)
                    {
                    case 0:
                        Knx_var_Rb(sPath, &iMaster, &iKnx, sRom[i], &xComment);
                        break;

                    case 1:
                        Knx_var_Hvac(sPath, &iMaster, &iKnx, sRom[i], &xComment);
                        break;

                    case 2:
                        Knx_var_Rt(sPath, &iMaster, &iKnx, sRom[i], &xComment);
                        break;

                    case 3:
                        Knx_var_Ry(sPath, &iMaster, &iKnx, sRom[i], &xComment);
                        break;

                    case 4:
                        Knx_var_Lh_OP(sPath, &iMaster, &iKnx, sRom[i], &xComment);
                        iKnxOutputs += 1;
                        break;

                    case 5:
                        Knx_var_Lh_CMD(sPath, &iMaster, &iKnx, sRom[i], &xComment);
                        iKnxOutputs += 1;
                        break;

                    case 6:
                        Knx_var_Lc_OP(sPath, &iMaster, &iKnx, sRom[i], &xComment);
                        iKnxOutputs += 1;
                        break;

                    case 7:
                        Knx_var_Lc_CMD(sPath, &iMaster, &iKnx, sRom[i], &xComment);
                        iKnxOutputs += 1;
                        break;

                    case 8:
                        Knx_var_Sp(sPath, &iMaster, &iKnx, sRom[i], &xComment);
                        break;

                    case 9:
                        Knx_var_Sp_Fb(sPath, &iMaster, &iKnx, sRom[i], &xComment);
                        break;

                    default:
                        break;
                    }
                }
            }
        }
        else
            break;
    }

    //Åpner output fil igjen
    fOutput.open(sPath, std::ios::app);

    //Ender lokal variabler, og starter på program
    fOutput << "</localVars>\n" + Tabs(3);
    fOutput << "</interface>\n" + Tabs(3);
    fOutput << "<body>\n" + Tabs(4);
    fOutput << "<ST>\n" << Tabs(5);
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\" />\n" << Tabs(5);
    fOutput << "</ST>\n" << Tabs(4);
    fOutput << "<addData>\n" << Tabs(5);
    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/cfc\" handleUnknown=\"implementation\">\n" << Tabs(4);
    fOutput << "<CFC>\n\t";

    fOutput.close();    //Lukker fil før funksjoner kjøres

    //Skriv CFC kode for KNX ouput interval
    Knx_cfc_Interval(sPath, iKnxOutputs);
    iCfc_id = 22;
    iCfc_Order = 7;

    //Resetter Knx variabler brukt i lokal variabel deklarering
    iMaster = 1;
    iKnx = 1;
    iKnxOutputs = 0;


    for (int i = 0; i < iMax; i++)
    {
        if (bUsed[i])
        {
            Knx_cfc_comment_a(sPath, sRom[i], &iCfc_id, iCfc_y);
            for (int j = 0; j < 10; j++)
            {
                if (j < sRomtype[i].size() && sRomtype[i].substr(j, 1) == "1")
                {
                    switch (j)
                    {
                    case 0:
                        Knx_cfc_Rb(sPath, sGVL, sAdresseFormat, sRom[i], &iMaster, &iKnx, &iCfc_Order, &iCfc_id, iCfc_y, iCfc_x);
                        iLast2 = iLast1;
                        iLast1 = j;
                        break;

                    case 1:
                        Knx_cfc_Hvac(sPath, sGVL, sAdresseFormat, sRom[i], &iMaster, &iKnx, &iCfc_Order, &iCfc_id, iCfc_y, iCfc_x);
                        iLast2 = iLast1;
                        iLast1 = j;
                        break;

                    case 2:
                        Knx_cfc_Rt(sPath, sGVL, sAdresseFormat, sRom[i], &iMaster, &iKnx, &iCfc_Order, &iCfc_id, iCfc_y, iCfc_x);
                        iLast2 = iLast1;
                        iLast1 = j;
                        break;

                    case 3:
                        Knx_cfc_Ry(sPath, sGVL, sAdresseFormat, sRom[i], &iMaster, &iKnx, &iCfc_Order, &iCfc_id, iCfc_y, iCfc_x);
                        iLast2 = iLast1;
                        iLast1 = j;
                        break;

                    case 4:
                        Knx_cfc_Lh_OP(sPath, sGVL, sAdresseFormat, sRom[i], &iMaster, &iKnx, &iCfc_Order, &iCfc_id, iCfc_y, iCfc_x, &iKnxOutputs);
                        iLast2 = iLast1;
                        iLast1 = j;
                        break;

                    case 5:
                        Knx_cfc_Lh_CMD(sPath, sGVL, sAdresseFormat, sRom[i], &iMaster, &iKnx, &iCfc_Order, &iCfc_id, iCfc_y, iCfc_x, &iKnxOutputs);
                        iLast2 = iLast1;
                        iLast1 = j;
                        break;

                    case 6:
                        Knx_cfc_Lc_OP(sPath, sGVL, sAdresseFormat, sRom[i], &iMaster, &iKnx, &iCfc_Order, &iCfc_id, iCfc_y, iCfc_x, &iKnxOutputs);
                        iLast2 = iLast1;
                        iLast1 = j;
                        break;

                    case 7:
                        Knx_cfc_Lc_CMD(sPath, sGVL, sAdresseFormat, sRom[i], &iMaster, &iKnx, &iCfc_Order, &iCfc_id, iCfc_y, iCfc_x, &iKnxOutputs);
                        iLast2 = iLast1;
                        iLast1 = j;
                        break;

                    case 8:
                        Knx_cfc_Sp(sPath, sGVL, sAdresseFormat, sRom[i], &iMaster, &iKnx, &iCfc_Order, &iCfc_id, iCfc_y, iCfc_x);
                        iLast2 = iLast1;
                        iLast1 = j;
                        break;

                    case 9:
                        Knx_cfc_Sp_Fb(sPath, sGVL, sAdresseFormat, sRom[i], &iMaster, &iKnx, &iCfc_Order, &iCfc_id, iCfc_y, iCfc_x);
                        iLast2 = iLast1;
                        iLast1 = j;
                        break;

                    default:
                        break;
                    }
                    if (iCfc_x >= 40 && (iLast1 < 2 || iLast1 == 5 || iLast1 == 7) && (iLast2 < 2 || iLast2 == 5 || iLast2 == 7))
                    {
                        iCfc_x = 2;
                        iCfc_y += 18;
                        xSpace = true;
                    }
                    else if (iCfc_x >= 40)
                    {
                        iCfc_x = 2;
                        iCfc_y += 19;
                        xSpace = true;
                    }
                    else
                    {
                        iCfc_x += 42;
                        xSpace = false;
                    }
                }
            }
            if (xSpace)
            {
                iCfc_x = 2;
                iCfc_y += 8;
            }
            else if ((iLast1 < 2 || iLast1 == 5 || iLast1 == 7) && (iLast2 < 2 || iLast2 == 5 || iLast2 == 7))
            {
                iCfc_x = 2;
                iCfc_y += 26;
            }
            else
            {
                iCfc_x = 2;
                iCfc_y += 27;
            }
        }
        else
            break;
    }


    fOutput.open(sPath, std::ios::app);

    //GVL
    fOutput << "</CFC>\n" + Tabs(1);
    fOutput << "</data>\n" + Tabs(1);
    fOutput << "</addData>\n" + Tabs(1);
    fOutput << "</body>\n" + Tabs(1);
    fOutput << "<addData />\n" + Tabs(1);
    fOutput << "</pou>\n" + Tabs(1);
    fOutput << "</pous>\n" + Tabs(1);
    fOutput << "</types>\n" + Tabs(1);
    fOutput << "<instances>\n" + Tabs(1);
    fOutput << "<configurations />\n" + Tabs(1);
    fOutput << "</instances>\n" + Tabs(1);
    fOutput << "<addData>\n" + Tabs(1);
    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/globalvars\" handleUnknown=\"implementation\">\n" + Tabs(2);
    fOutput << "<globalVars name=\"" << sGVL <</*"\" retain=\"true\" persistent=\"true\*/"\">\n" + Tabs(3);

    for (int i = 0; i < iMax; i++)
    {
        if (bUsed[i])
        {

            fOutput << "<variable name=\"" << sAdresseFormat << "_" << sRom[i] << "\">\n" + Tabs(4);
            fOutput << "<type>\n" + Tabs(5);
            fOutput << "<derived name=\"dtRomtype_" << sRomtype[i] << "\" />\n" + Tabs(4);
            fOutput << "</type>\n" + Tabs(4);
            fOutput << "<documentation>\n" + Tabs(4);
            fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">" << sKommentar[i] << "</xhtml>\n" + Tabs(3);
            fOutput << "</documentation>\n" + Tabs(3);
            fOutput << "</variable>\n" + Tabs(3);
        }
        else
            break;
    }
    fOutput << "<addData>" << std::endl << Tabs(4);

    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/attributes\" handleUnknown=\"implementation\">\n" + Tabs(5);
    fOutput << "<Attributes>\n" + Tabs(6);
    fOutput << "<Attribute Name=\"qualified_only\" Value=\"\" />\n" + Tabs(5);
    fOutput << "</Attributes>\n" + Tabs(4);
    fOutput << "</data>\n" + Tabs(4);

    fOutput << "<data name=\"http://www.3s-software.com/plcopenxml/buildproperties\" handleUnknown=\"implementation\">\n" + Tabs(5);
    fOutput << "<BuildProperties>\n" + Tabs(6);
    fOutput << "<LinkAlways>true</LinkAlways>\n" + Tabs(5);
    fOutput << "</BuildProperties>\n" + Tabs(4);
    fOutput << "</data>\n" + Tabs(3);
    fOutput << "</addData>\n" + Tabs(2);
    fOutput << "</globalVars>\n" + Tabs(1);
    fOutput << "</data>\n";
    fOutput << "</addData>\n";
    fOutput << "</project>" << std::endl;

    fOutput.close();
}
#endif