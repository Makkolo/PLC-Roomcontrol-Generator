#pragma once
#ifndef roomcontrolXmlLib
#define roomcontrolXmlLib
#include <iostream>\n\t";
#include <fstream>\n\t";
#include <windows.h>\n\t";
#include "mortLib.h"




//Lokal variabler
void Knx_var_Rb(std::string& sPath, int* iMaster, int* iKnx, std::string& sRom, bool* xComment)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<variable name=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RB601_V\">\n\t";
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

    fOutput.close();
    (*iKnx)++;
    return;
}


void Knx_var_Hvac(std::string& sPath, int* iMaster, int* iKnx, std::string& sRom, bool* xComment)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<variable name=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RB601_HVAC\">\n\t";
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

    fOutput.close();
    (*iKnx)++;
    return;
}


void Knx_var_Rt(std::string& sPath, int* iMaster, int* iKnx, std::string& sRom, bool* xComment)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<variable name=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RT601_CT\">\n\t";
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

    fOutput.close();
    (*iKnx)++;
    return;
}

void Knx_var_Ry(std::string& sPath, int* iMaster, int* iKnx, std::string& sRom, bool* xComment)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<variable name=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RY601_CV\">\n\t";
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

    fOutput.close();
    (*iKnx)++;
    return;
}

void Knx_var_Lh_OP(std::string& sPath, int* iMaster, int* iKnx, std::string& sRom, bool* xComment)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<variable name=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LH601_OP\">\n\t";
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

    fOutput.close();
    (*iKnx)++;
    return;
}

void Knx_var_Lh_CMD(std::string& sPath, int* iMaster, int* iKnx, std::string& sRom, bool* xComment)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<variable name=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LH601_CMD\">\n\t";
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

    fOutput.close();
    (*iKnx)++;
    return;
}

void Knx_var_Lc_OP(std::string& sPath, int* iMaster, int* iKnx, std::string& sRom, bool* xComment)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<variable name=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LC601_OP\">\n\t";
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

    fOutput.close();
    (*iKnx)++;
    return;
}

void Knx_var_Lc_CMD(std::string& sPath, int* iMaster, int* iKnx, std::string& sRom, bool* xComment)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<variable name=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LC601_CMD\">\n\t";
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

    fOutput.close();
    (*iKnx)++;
    return;
}

void Knx_var_Sp(std::string& sPath, int* iMaster, int* iKnx, std::string& sRom, bool* xComment)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<variable name=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RT601_SP_FB\">\n\t";
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

    fOutput.close();
    (*iKnx)++;
    return;
}

void Knx_var_Sp_Fb(std::string& sPath, int* iMaster, int* iKnx, std::string& sRom, bool* xComment)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<variable name=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RT601_SP\">\n\t";
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

    fOutput.close();
    (*iKnx)++;
    return;
}










//----------------------------------------------------------------------------------------------------------------------------------------
//CFC koder
void Knx_cfc_comment_a(std::string& sPath, std::string& sRom, int* iCfc_Id, int& iCfc_y)
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

void Knx_cfc_comment_b(std::string& sPath, std::string& sRom, int* iCfc_Id, int& iCfc_y)
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



void Knx_cfc_Interval(std::string& sPath, int& iKnxOutputs)
{
    std::ofstream fOutput(sPath, std::ios::app);

    fOutput << "<comment localId=\"0\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"7\" y=\"2\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">KNX Sending interval</xhtml>\n\t";

    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";
    fOutput << "<inVariable localId=\"1\">\n\t";
    fOutput << "<position x=\"2\" y=\"6\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>t#2M</expression>\n\t";

    fOutput << "</inVariable>\n\t";
    fOutput << "<connector localId=\"2\" name=\"\">\n\t";
    fOutput << "<position x=\"1\" y=\"149\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"1\" formalParameter=\"t#2M\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<block localId=\"3\" executionOrderId=\"0\" typeName=\"OSCAT_BASIC.CLK_PRG\" instanceName=\"Interval\">\n\t";
    fOutput << "<position x=\"7\" y=\"4\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"PT\">\n\t";
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
    fOutput << "<position x=\"11\" y=\"183\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"3\" formalParameter=\"Q\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<block localId=\"5\" executionOrderId=\"1\" typeName=\"BOOL_TO_INT\">\n\t";
    fOutput << "<position x=\"20\" y=\"4\" />\n\t";
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
    fOutput << "<position x=\"11\" y=\"183\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"5\" formalParameter=\"\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<inVariable localId=\"7\">\n\t";
    fOutput << "<position x=\"25\" y=\"8\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>i</expression>\n\t";
    fOutput << "</inVariable>\n\t";
    fOutput << "<connector localId=\"8\" name=\"\">\n\t";
    fOutput << "<position x=\"11\" y=\"183\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"7\" formalParameter=\"i\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<block localId=\"9\" executionOrderId=\"2\" typeName=\"ADD\">\n\t";
    fOutput << "<position x=\"31\" y=\"4\" />\n\t";
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
    fOutput << "<position x=\"11\" y=\"183\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"9\" formalParameter=\"\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<outVariable localId=\"11\" executionOrderId=\"3\">\n\t";
    fOutput << "<position x=\"36\" y=\"6\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
    fOutput << "<connection refLocalId=\"10\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>i</expression>\n\t";
    fOutput << "</outVariable>\n\t";
    fOutput << "<connector localId=\"12\" name=\"\">\n\t";
    fOutput << "<position x=\"11\" y=\"183\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"7\" formalParameter=\"i\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<inVariable localId=\"13\">\n\t";
    fOutput << "<position x=\"25\" y=\"11\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";

    fOutput << "<expression>" << iKnxOutputs << "</expression>\n\t";

    fOutput << "</inVariable>\n\t";
    fOutput << "<connector localId=\"14\" name=\"\">\n\t";
    fOutput << "<position x=\"11\" y=\"183\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"13\" formalParameter=\"" << iKnxOutputs << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"15\" executionOrderId=\"4\" typeName=\"GT\">\n\t";
    fOutput << "<position x=\"31\" y=\"8\" />\n\t";
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
    fOutput << "<position x=\"11\" y=\"183\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"15\" formalParameter=\"\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"17\">\n\t";
    fOutput << "<position x=\"36\" y=\"11\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>0</expression>\n\t";
    fOutput << "</inVariable>\n\t";
    fOutput << "<connector localId=\"18\" name=\"\">\n\t";
    fOutput << "<position x=\"11\" y=\"183\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"17\" formalParameter=\"0\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"19\" executionOrderId=\"5\" typeName=\"MOVE\">\n\t";
    fOutput << "<position x=\"41\" y=\"8\" />\n\t";
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
    fOutput << "<position x=\"11\" y=\"18\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"19\" formalParameter=\"\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<outVariable localId=\"21\" executionOrderId=\"6\">\n\t";
    fOutput << "<position x=\"48\" y=\"11\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"0\" y=\"0\" />\n\t";
    fOutput << "<connection refLocalId=\"20\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>i</expression>\n\t";
    fOutput << "</outVariable>\n\t";
    fOutput.close();
    return;
}









void Knx_cfc_Rb(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int& iCfc_y, int& iCfc_x)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<comment localId=\"" << (1 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (25 + iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">RB601_V</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    fOutput << "<inVariable localId=\"" << (2 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (1 + 29 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iMaster << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (3 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (05 + iCfc_x) << "\" y=\"" << (1 + 454 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" formalParameter=\"" << *iMaster << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (4 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (1 + 30 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iKnx << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (5 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (05 + iCfc_x) << "\" y=\"" << (1 + 454 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (6 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (16 + iCfc_x) << "\" y=\"" << (1 + 35 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>typDPT</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (7 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (05 + iCfc_x) << "\" y=\"" << (1 + 454 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"" << (8 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbDPT_Switch_pro\" instanceName=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RB601_V\">\n\t";

    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (1 + 27 + iCfc_y) << "\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + 0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + 1 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xSwitch_IN\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + 2 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + 3 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + 4 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + 5 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables>\n\t";
    fOutput << "<variable formalParameter=\"typDPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + 6 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inOutVariables>\n\t";
    fOutput << "<outputVariables>\n\t";
    fOutput << "<variable formalParameter=\"xSwitch_OUT\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + 0 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + 1 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + 2 + iCfc_y) << "\" />\n\t";
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

    fOutput << "<connector localId=\"" << (9 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (05 + iCfc_x) << "\" y=\"" << (1 + 288 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" formalParameter=\"xSwitch_OUT\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (10 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"" << (37 + iCfc_x) << "\" y=\"" << (1 + 29 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + 0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";

    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RB601_V</expression>\n\t";

    fOutput << "</outVariable>\n\t";


    (*iCfc_Id) += 11;
    (*iCfc_Order) += 2;
    (*iKnx)++;
    fOutput.close();
    return;
}







void Knx_cfc_Hvac(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int& iCfc_y, int& iCfc_x)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (25 + iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">RB601_HVAC</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";
    fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (30 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";

    fOutput << "<expression>" << *iMaster << "</expression >\n\t";

    fOutput << "</inVariable>\n\t";
    fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (05 + iCfc_x) << "\" y=\"" << (455 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << *iMaster << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (31 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";

    fOutput << "<expression>" << *iKnx << "</expression >\n\t";

    fOutput << "</inVariable>\n\t";
    fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (05 + iCfc_x) << "\" y=\"" << (455 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (16 + iCfc_x) << "\" y=\"" << (36 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>typDPT</expression>\n\t";
    fOutput << "</inVariable>\n\t";
    fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (05 + iCfc_x) << "\" y=\"" << (455 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"" << (7 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbDPT_Switch_pro\" instanceName=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RB601_HVAC\">\n\t";

    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (28 + iCfc_y) << "\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + 0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + 1 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xSwitch_IN\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + 2 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + 3 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + 4 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + 5 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables>\n\t";
    fOutput << "<variable formalParameter=\"typDPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + 6 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + 0 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + 1 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + 2 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<position x=\"" << (05 + iCfc_x) << "\" y=\"" << (289 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"xSwitch_OUT\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<outVariable localId=\"" << (9 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"" << (37 + iCfc_x) << "\" y=\"" << (30 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + 0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";

    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RB601_HVAC</expression>\n\t";

    fOutput << "</outVariable>\n\t";

    (*iCfc_Id) += 10;
    (*iCfc_Order) += 2;
    (*iKnx)++;
    fOutput.close();
    return;
}









void Knx_cfc_Rt(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int& iCfc_y, int& iCfc_x)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (25 + iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">RT601_CT</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (30 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";

    fOutput << "<expression>" << *iMaster << "</expression>\n\t";

    fOutput << "</inVariable>\n\t";
    fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << *iMaster << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (31 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";

    fOutput << "<expression>" << *iKnx << "</expression>\n\t";

    fOutput << "</inVariable>\n\t";
    fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (16 + iCfc_x) << "\" y=\"" << (37 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";

    fOutput << "<expression>typDPT</expression>\n\t";

    fOutput << "</inVariable>\n\t";
    fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<block localId=\"" << (7 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbDPT_Value_Temp_pro\" instanceName=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RT601_CT\">\n\t";
    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (28 + iCfc_y) << "\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"rValue_IN\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (3 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (4 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (5 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"rSendOnDelta\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (6 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables>\n\t";
    fOutput << "<variable formalParameter=\"typDPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (7 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"rValue_OUT\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<outVariable localId=\"" << (9 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"" << (37 + iCfc_x) << "\" y=\"" << (30 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT601_CT</expression>\n\t";
    fOutput << "</outVariable>\n\t";

    (*iCfc_Order) += 2;
    (*iCfc_Id) += 10;
    (*iKnx)++;
    fOutput.close();
    return;
}







void Knx_cfc_Ry(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int& iCfc_y, int& iCfc_x)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (25 + iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">RY601_CV</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";
    fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (30 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";

    fOutput << "<expression>" << *iMaster << "</expression >\n\t";

    fOutput << "</inVariable>\n\t";
    fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (05 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << *iMaster << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";
    fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (31 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";

    fOutput << "<expression>" << *iKnx << "</expression >\n\t";

    fOutput << "</inVariable>\n\t";
    fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (05 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (16 + iCfc_x) << "\" y=\"" << (37 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>typDPT</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (05 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"" << (7 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbDPT_Value_AirQuality_pro\" instanceName=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RY601_CV\">\n\t";

    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (28 + iCfc_y) << "\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (18 + 0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (18 + 1 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"rValue_IN\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (18 + 2 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (18 + 3 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (18 + 4 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (18 + 5 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"rSendOnDelta\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 6 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inputVariables>\n\t";

    fOutput << "<inOutVariables>\n\t";
    fOutput << "<variable formalParameter=\"typDPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (18 + 6 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (18 + 0 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (18 + 1 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (18 + 2 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<position x=\"" << (05 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"rValue_OUT\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (9 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"" << (37 + iCfc_x) << "\" y=\"" << (30 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (18 + 0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";

    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RY601_CV</expression>\n\t";

    fOutput << "</outVariable>\n\t";

    (*iCfc_Order) += 2;
    (*iCfc_Id) += 10;
    (*iKnx)++;
    fOutput.close();
    return;
}










///
void Knx_cfc_Lh_OP(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int& iCfc_y, int& iCfc_x, int* iKnxOutputs)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (25 + iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LH601_OP</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (30 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iMaster << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (9 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << *iMaster << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (31 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iKnx << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (9 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (2 + iCfc_x) << "\" y=\"" << (32 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LH601_OP</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (2 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LH601_OP\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (11 + iCfc_x) << "\" y=\"" << (35 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>i</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"i\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (11 + iCfc_x) << "\" y=\"" << (36 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iKnxOutputs << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"" << *iKnxOutputs << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"EQ\">\n\t";
    fOutput << "<position x=\"" << (16 + iCfc_x) << "\" y=\"" << (33 + iCfc_y) << "\" />\n\t";

    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"In1\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"In2\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables />\n\t";
    fOutput << "<outputVariables>\n\t";
    fOutput << "<variable formalParameter=\"Out1\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (16 + iCfc_x) << "\" y=\"" << (37 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>typDPT</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (9 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"fbDPT_Scaling_pro\" instanceName=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LH601_OP\">\n\t";

    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (28 + iCfc_y) << "\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"rValue_IN\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (3 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (4 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (5 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"rSendOnDelta\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (6 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables>\n\t";
    fOutput << "<variable formalParameter=\"typDPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (7 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + iCfc_y) << "\" />\n\t";
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
    fOutput.close();
    return;
}











void Knx_cfc_Lh_CMD(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int& iCfc_y, int& iCfc_x, int* iKnxOutputs)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (25 + iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LH601_CMD</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (30 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iMaster << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (9 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << *iMaster << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (31 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iKnx << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (9 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (2 + iCfc_x) << "\" y=\"" << (32 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LH601_CMD</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (2 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LH601_CMD\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (6 + iCfc_x) << "\" y=\"" << (35 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>i</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"i\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (6 + iCfc_x) << "\" y=\"" << (36 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iKnxOutputs << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"" << *iKnxOutputs << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"EQ\">\n\t";
    fOutput << "<position x=\"" << (11 + iCfc_x) << "\" y=\"" << (33 + iCfc_y) << "\" />\n\t";

    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"In1\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "<variable formalParameter=\"In2\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";

    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables />\n\t";
    fOutput << "<outputVariables>\n\t";
    fOutput << "<variable formalParameter=\"Out1\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (16 + iCfc_x) << "\" y=\"" << (36 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>typDPT</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (9 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"fbDPT_Switch_pro\" instanceName=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LH601_CMD\">\n\t";

    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (28 + iCfc_y) << "\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xSwitch_IN\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (3 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (4 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (5 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables>\n\t";
    fOutput << "<variable formalParameter=\"typDPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (7 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (1 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (2 + iCfc_y) << "\" />\n\t";
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
    fOutput.close();
    return;
}





void Knx_cfc_Lc_OP(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int& iCfc_y, int& iCfc_x, int* iKnxOutputs)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (25 + iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LC601_OP</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (30 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iMaster << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (9 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << *iMaster << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (31 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iKnx << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (9 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (2 + iCfc_x) << "\" y=\"" << (32 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LC601_OP</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (2 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LC601_OP\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (11 + iCfc_x) << "\" y=\"" << (35 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>i</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"i\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (11 + iCfc_x) << "\" y=\"" << (36 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iKnxOutputs << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"" << *iKnxOutputs << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"EQ\">\n\t";
    fOutput << "<position x=\"" << (16 + iCfc_x) << "\" y=\"" << (33 + iCfc_y) << "\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"In1\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"In2\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 1 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables />\n\t";
    fOutput << "<outputVariables>\n\t";
    fOutput << "<variable formalParameter=\"Out1\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 0 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (16 + iCfc_x) << "\" y=\"" << (37 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>typDPT</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (9 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"fbDPT_Scaling_pro\" instanceName=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LC601_OP\">\n\t";
    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (28 + iCfc_y) << "\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 1 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"rValue_IN\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 2 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 3 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 4 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 5 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"rSendOnDelta\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 6 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables>\n\t";
    fOutput << "<variable formalParameter=\"typDPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 7 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 0 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 1 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 2 + iCfc_y) << "\" />\n\t";
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
    fOutput.close();
    return;
}





void Knx_cfc_Lc_CMD(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int& iCfc_y, int& iCfc_x, int* iKnxOutputs)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (25 + iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">LC601_CMD</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (30 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iMaster << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (9 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << *iMaster << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (31 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iKnx << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (9 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (2 + iCfc_x) << "\" y=\"" << (32 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LC601_CMD</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (2 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".LC601_CMD\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (6 + iCfc_x) << "\" y=\"" << (35 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>i</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"i\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (6 + iCfc_x) << "\" y=\"" << (36 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iKnxOutputs << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"" << *iKnxOutputs << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"EQ\">\n\t";
    fOutput << "<position x=\"" << (11 + iCfc_x) << "\" y=\"" << (33 + iCfc_y) << "\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"In1\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"In2\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 1 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (10 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables />\n\t";
    fOutput << "<outputVariables>\n\t";
    fOutput << "<variable formalParameter=\"Out1\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 0 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<position x=\"" << (5 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (11 + *iCfc_Id) << "\" formalParameter=\"\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (13 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (16 + iCfc_x) << "\" y=\"" << (36 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>typDPT</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (14 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (9 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (13 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"" << (15 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\" typeName=\"fbDPT_Switch_pro\" instanceName=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_LC601_CMD\">\n\t";
    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (28 + iCfc_y) << "\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 1 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xSwitch_IN\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 2 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 3 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (12 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 4 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 5 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables>\n\t";
    fOutput << "<variable formalParameter=\"typDPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 7 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 0 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 1 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 + iCfc_x) << "\" y=\"" << (16 + 2 + iCfc_y) << "\" />\n\t";
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
    fOutput.close();
    return;
}












void Knx_cfc_Sp(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int& iCfc_y, int& iCfc_x)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (iCfc_y + 25) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">RT601_SP</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (iCfc_y + 30) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iMaster << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (9 + iCfc_x) << "\" y=\"" << (iCfc_y + 275) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << *iMaster << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (iCfc_y + 31) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iKnx << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (9 + iCfc_x) << "\" y=\"" << (iCfc_y + 275) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (1 + iCfc_x) << "\" y=\"" << (iCfc_y + 32) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT601_SP_D</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (1 + iCfc_x) << "\" y=\"" << (iCfc_y + 275) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT601_SP_D\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (7 + *iCfc_Id) << "\" negated=\"true\">\n\t";
    fOutput << "<position x=\"" << (1 + iCfc_x) << "\" y=\"" << (iCfc_y + 33) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RB601_HVAC</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (8 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (1 + iCfc_x) << "\" y=\"" << (iCfc_y + 275) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RB601_HVAC\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (9 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (16 + iCfc_x) << "\" y=\"" << (iCfc_y + 37) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>typDPT</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (10 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (9 + iCfc_x) << "\" y=\"" << (iCfc_y + 275) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (9 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"" << (11 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbDPT_Value_Temp_pro\" instanceName=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RT601_SP\">\n\t";

    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (iCfc_y + 28) << "\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (iCfc_y + 0) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (iCfc_y + 1) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"rValue_IN\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (iCfc_y + 2) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (6 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (iCfc_y + 3) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (iCfc_y + 4) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (iCfc_y + 5) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"rSendOnDelta\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (iCfc_y + 6) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables>\n\t";
    fOutput << "<variable formalParameter=\"typDPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (iCfc_y + 7) << "\" />\n\t";
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
    fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (iCfc_y + 0) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (iCfc_y + 1) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 1) << "\" y=\"" << (iCfc_y + 2) << "\" />\n\t";
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
    fOutput.close();
    return;
}






void Knx_cfc_Sp_Fb(std::string& sPath, std::string& sGVL, std::string& sAdresseFormat, std::string& sRom, int* iMaster, int* iKnx, int* iCfc_Order, int* iCfc_Id, int& iCfc_y, int& iCfc_x)
{
    std::ofstream fOutput(sPath, std::ios::app);
    std::string sPreset = Knx_Preset(*iKnx);
    Knx_Master(iMaster, iKnx);

    fOutput << "<comment localId=\"" << (0 + *iCfc_Id) << "\" height=\"0\" width=\"0\">\n\t";
    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (25 + iCfc_y) << "\" />\n\t";
    fOutput << "<content>\n\t";
    fOutput << "<xhtml xmlns=\"http://www.w3.org/1999/xhtml\">RT601_SP Feedback</xhtml>\n\t";
    fOutput << "</content>\n\t";
    fOutput << "</comment>\n\t";

    fOutput << "<inVariable localId=\"" << (1 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (30 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iMaster << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (2 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (7 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (1 + *iCfc_Id) << "\" formalParameter=\"" << *iMaster << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (3 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (18 + iCfc_x) << "\" y=\"" << (31 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>" << *iKnx << "</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (4 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (7 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (3 + *iCfc_Id) << "\" formalParameter=\"" << *iKnx << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<inVariable localId=\"" << (5 + *iCfc_Id) << "\">\n\t";
    fOutput << "<position x=\"" << (16 + iCfc_x) << "\" y=\"" << (37 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "<expression>typDPT</expression>\n\t";
    fOutput << "</inVariable>\n\t";

    fOutput << "<connector localId=\"" << (6 + *iCfc_Id) << "\" name=\"\">\n\t";
    fOutput << "<position x=\"" << (7 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (5 + *iCfc_Id) << "\" formalParameter=\"typDPT\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<block localId=\"" << (7 + *iCfc_Id) << "\" executionOrderId=\"" << (0 + *iCfc_Order) << "\" typeName=\"fbDPT_Value_Temp_pro\" instanceName=\"M" << *iMaster << "_" << sPreset << *iKnx << "_" << sRom << "_RT601_SP_FB\">\n\t";
    fOutput << "<position x=\"" << (23 + iCfc_x) << "\" y=\"" << (28 + iCfc_y) << "\" />\n\t";
    fOutput << "<inputVariables>\n\t";
    fOutput << "<variable formalParameter=\"bPortKNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (2 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"dwIndex_DPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (1 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (4 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"rValue_IN\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (2 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (3 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xRead_KNX\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (4 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"tMinSendTime\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (5 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"rSendOnDelta\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (6 + iCfc_y) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "</inputVariables>\n\t";
    fOutput << "<inOutVariables>\n\t";
    fOutput << "<variable formalParameter=\"typDPT\">\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (7 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xUpdate_PLC\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (1 + iCfc_y) << "\" />\n\t";
    fOutput << "<expression />\n\t";
    fOutput << "</connectionPointOut>\n\t";
    fOutput << "</variable>\n\t";
    fOutput << "<variable formalParameter=\"xTimeOut\">\n\t";
    fOutput << "<connectionPointOut>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (2 + iCfc_y) << "\" />\n\t";
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
    fOutput << "<position x=\"" << (0 + iCfc_x) << "\" y=\"" << (275 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<connection refLocalId=\"" << (7 + *iCfc_Id) << "\" formalParameter=\"rValue_OUT\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "</connector>\n\t";

    fOutput << "<outVariable localId=\"" << (9 + *iCfc_Id) << "\" executionOrderId=\"" << (1 + *iCfc_Order) << "\">\n\t";
    fOutput << "<position x=\"" << (37 + iCfc_x) << "\" y=\"" << (30 + iCfc_y) << "\" />\n\t";
    fOutput << "<connectionPointIn>\n\t";
    fOutput << "<relPosition x=\"" << (0 - 2) << "\" y=\"" << (0 + iCfc_y) << "\" />\n\t";
    fOutput << "<connection refLocalId=\"" << (8 + *iCfc_Id) << "\" />\n\t";
    fOutput << "</connectionPointIn>\n\t";
    fOutput << "<expression>" << sGVL << "." << sAdresseFormat << "_" << sRom << ".RT601_SP_IN</expression>\n\t";
    fOutput << "</outVariable>\n\t";

    (*iCfc_Order) += 2;
    (*iCfc_Id) += 10;
    (*iKnx)++;
    fOutput.close();
    return;
}
#endif