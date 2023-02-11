﻿#include <StdInc.h>
#pragma optimize("", off)
#include <iphlpapi.h>
#include <winsock2.h>
#include <sysinfoapi.h>
#include "Utility/InitFunction.h"
#include "Functions/Global.h"

#ifndef _M_IX86
u_short HttpPort = 88;
const char* powerOn = "http://teknoparrot.xyz/allnet/poweron";
const char* dlOrder = "http://teknoparrot.xyz/allnet/downloadorder";
const char* localhost = "teknoparrot.xyz";

static const unsigned char AMConfig[] = {
  0x5b, 0x41, 0x4d, 0x55, 0x70, 0x64, 0x61, 0x74, 0x65, 0x72, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67,
  0x5d, 0x20, 0x0d, 0x0a, 0x3b, 0x3b, 0x20, 0x41, 0x4d, 0x55, 0x70, 0x64, 0x61, 0x74, 0x65, 0x72,
  0x20, 0x88, 0xea, 0x94, 0xca, 0x90, 0xdd, 0x92, 0xe8, 0x0d, 0x0a, 0x61, 0x6d, 0x75, 0x63, 0x66,
  0x67, 0x2d, 0x74, 0x69, 0x74, 0x6c, 0x65, 0x3d, 0x98, 0x70, 0x8a, 0xdd, 0x83, 0x7e, 0x83, 0x62,
  0x83, 0x68, 0x83, 0x69, 0x83, 0x43, 0x83, 0x67, 0x20, 0x4d, 0x41, 0x58, 0x49, 0x4d, 0x55, 0x4d,
  0x20, 0x54, 0x55, 0x4e, 0x45, 0x20, 0x36, 0x0d, 0x0a, 0x61, 0x6d, 0x75, 0x63, 0x66, 0x67, 0x2d,
  0x6c, 0x61, 0x6e, 0x67, 0x3d, 0x4a, 0x50, 0x0d, 0x0a, 0x61, 0x6d, 0x75, 0x63, 0x66, 0x67, 0x2d,
  0x63, 0x6f, 0x75, 0x6e, 0x74, 0x64, 0x6f, 0x77, 0x6e, 0x3d, 0x35, 0x0d, 0x0a, 0x61, 0x6d, 0x75,
  0x63, 0x66, 0x67, 0x2d, 0x68, 0x5f, 0x72, 0x65, 0x73, 0x6f, 0x6c, 0x3d, 0x31, 0x33, 0x36, 0x30,
  0x0d, 0x0a, 0x61, 0x6d, 0x75, 0x63, 0x66, 0x67, 0x2d, 0x76, 0x5f, 0x72, 0x65, 0x73, 0x6f, 0x6c,
  0x3d, 0x37, 0x36, 0x38, 0x0d, 0x0a, 0x61, 0x6d, 0x75, 0x63, 0x66, 0x67, 0x2d, 0x6c, 0x6f, 0x67,
  0x66, 0x69, 0x6c, 0x65, 0x3d, 0x61, 0x6d, 0x75, 0x70, 0x64, 0x61, 0x74, 0x65, 0x72, 0x2e, 0x6c,
  0x6f, 0x67, 0x0d, 0x0a, 0x61, 0x6d, 0x75, 0x63, 0x66, 0x67, 0x2d, 0x67, 0x61, 0x6d, 0x65, 0x5f,
  0x72, 0x65, 0x76, 0x3d, 0x31, 0x0d, 0x0a, 0x0d, 0x0a, 0x5b, 0x41, 0x4d, 0x41, 0x75, 0x74, 0x68,
  0x64, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x5d, 0x20, 0x0d, 0x0a, 0x3b, 0x3b, 0x20, 0x41, 0x4d,
  0x41, 0x75, 0x74, 0x68, 0x64, 0x20, 0x88, 0xea, 0x94, 0xca, 0x90, 0xdd, 0x92, 0xe8, 0x0d, 0x0a,
  0x61, 0x6d, 0x64, 0x63, 0x66, 0x67, 0x2d, 0x61, 0x75, 0x74, 0x68, 0x54, 0x79, 0x70, 0x65, 0x3d,
  0x41, 0x4c, 0x4c, 0x2e, 0x4e, 0x45, 0x54, 0x0d, 0x0a, 0x61, 0x6d, 0x64, 0x63, 0x66, 0x67, 0x2d,
  0x73, 0x6c, 0x65, 0x65, 0x70, 0x54, 0x69, 0x6d, 0x65, 0x3d, 0x35, 0x30, 0x0d, 0x0a, 0x61, 0x6d,
  0x64, 0x63, 0x66, 0x67, 0x2d, 0x72, 0x65, 0x73, 0x6f, 0x4e, 0x61, 0x6d, 0x65, 0x54, 0x69, 0x6d,
  0x65, 0x6f, 0x75, 0x74, 0x3d, 0x31, 0x38, 0x30, 0x0d, 0x0a, 0x61, 0x6d, 0x64, 0x63, 0x66, 0x67,
  0x2d, 0x77, 0x72, 0x69, 0x74, 0x61, 0x62, 0x6c, 0x65, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x3d,
  0x57, 0x72, 0x69, 0x74, 0x61, 0x62, 0x6c, 0x65, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x2e, 0x69,
  0x6e, 0x69, 0x0d, 0x0a, 0x61, 0x6d, 0x64, 0x63, 0x66, 0x67, 0x2d, 0x73, 0x68, 0x6f, 0x77, 0x43,
  0x6f, 0x6e, 0x73, 0x6f, 0x6c, 0x65, 0x3d, 0x45, 0x4e, 0x41, 0x42, 0x4c, 0x45, 0x0d, 0x0a, 0x61,
  0x6d, 0x64, 0x63, 0x66, 0x67, 0x2d, 0x6c, 0x6f, 0x67, 0x66, 0x69, 0x6c, 0x65, 0x3d, 0x2d, 0x0d,
  0x0a, 0x61, 0x6d, 0x64, 0x63, 0x66, 0x67, 0x2d, 0x65, 0x78, 0x70, 0x6f, 0x72, 0x74, 0x5f, 0x6c,
  0x6f, 0x67, 0x3d, 0x41, 0x6d, 0x41, 0x75, 0x74, 0x68, 0x64, 0x4c, 0x6f, 0x67, 0x2e, 0x7a, 0x69,
  0x70, 0x0d, 0x0a, 0x0d, 0x0a, 0x5b, 0x41, 0x6c, 0x6c, 0x6e, 0x65, 0x74, 0x43, 0x6f, 0x6e, 0x66,
  0x69, 0x67, 0x5d, 0x20, 0x0d, 0x0a, 0x3b, 0x3b, 0x20, 0x41, 0x4c, 0x4c, 0x2e, 0x4e, 0x65, 0x74,
  0x20, 0x88, 0xea, 0x94, 0xca, 0x90, 0xdd, 0x92, 0xe8, 0x0d, 0x0a, 0x61, 0x6c, 0x6c, 0x63, 0x66,
  0x67, 0x2d, 0x67, 0x61, 0x6d, 0x65, 0x49, 0x44, 0x3d, 0x53, 0x42, 0x57, 0x4a, 0x0d, 0x0a, 0x61,
  0x6c, 0x6c, 0x63, 0x66, 0x67, 0x2d, 0x67, 0x61, 0x6d, 0x65, 0x56, 0x65, 0x72, 0x3d, 0x39, 0x2e,
  0x30, 0x30, 0x0d, 0x0a, 0x0d, 0x0a, 0x5b, 0x41, 0x6c, 0x6c, 0x6e, 0x65, 0x74, 0x4f, 0x70, 0x74,
  0x69, 0x6f, 0x6e, 0x52, 0x65, 0x76, 0x61, 0x6c, 0x54, 0x69, 0x6d, 0x65, 0x5d, 0x0d, 0x0a, 0x3b,
  0x3b, 0x20, 0x41, 0x4c, 0x4c, 0x2e, 0x4e, 0x65, 0x74, 0x20, 0x8d, 0xc4, 0x94, 0x46, 0x8f, 0xd8,
  0x8e, 0x9e, 0x8d, 0x8f, 0x90, 0xdd, 0x92, 0xe8, 0x0d, 0x0a, 0x61, 0x6c, 0x6c, 0x6f, 0x70, 0x74,
  0x2d, 0x72, 0x65, 0x76, 0x61, 0x6c, 0x5f, 0x68, 0x6f, 0x75, 0x72, 0x3d, 0x37, 0x0d, 0x0a, 0x61,
  0x6c, 0x6c, 0x6f, 0x70, 0x74, 0x2d, 0x72, 0x65, 0x76, 0x61, 0x6c, 0x5f, 0x6d, 0x69, 0x6e, 0x75,
  0x74, 0x65, 0x3d, 0x30, 0x0d, 0x0a, 0x61, 0x6c, 0x6c, 0x6f, 0x70, 0x74, 0x2d, 0x72, 0x65, 0x76,
  0x61, 0x6c, 0x5f, 0x73, 0x65, 0x63, 0x6f, 0x6e, 0x64, 0x3d, 0x30, 0x0d, 0x0a, 0x0d, 0x0a, 0x5b,
  0x41, 0x6c, 0x6c, 0x6e, 0x65, 0x74, 0x4f, 0x70, 0x74, 0x69, 0x6f, 0x6e, 0x54, 0x69, 0x6d, 0x65,
  0x6f, 0x75, 0x74, 0x5d, 0x0d, 0x0a, 0x3b, 0x3b, 0x20, 0x41, 0x4c, 0x4c, 0x2e, 0x4e, 0x65, 0x74,
  0x20, 0x92, 0xca, 0x90, 0x4d, 0x83, 0x5e, 0x83, 0x43, 0x83, 0x80, 0x83, 0x41, 0x83, 0x45, 0x83,
  0x67, 0x90, 0xdd, 0x92, 0xe8, 0x0d, 0x0a, 0x61, 0x6c, 0x6c, 0x6f, 0x70, 0x74, 0x2d, 0x74, 0x69,
  0x6d, 0x65, 0x6f, 0x75, 0x74, 0x5f, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x3d, 0x36, 0x30,
  0x30, 0x30, 0x30, 0x20, 0x20, 0x0d, 0x0a, 0x61, 0x6c, 0x6c, 0x6f, 0x70, 0x74, 0x2d, 0x74, 0x69,
  0x6d, 0x65, 0x6f, 0x75, 0x74, 0x5f, 0x73, 0x65, 0x6e, 0x64, 0x3d, 0x36, 0x30, 0x30, 0x30, 0x30,
  0x0d, 0x0a, 0x61, 0x6c, 0x6c, 0x6f, 0x70, 0x74, 0x2d, 0x74, 0x69, 0x6d, 0x65, 0x6f, 0x75, 0x74,
  0x5f, 0x72, 0x65, 0x63, 0x76, 0x3d, 0x36, 0x30, 0x30, 0x30, 0x30, 0x0d, 0x0a, 0x0d, 0x0a, 0x5b,
  0x4d, 0x75, 0x63, 0x68, 0x61, 0x41, 0x70, 0x70, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x5d, 0x0d,
  0x0a, 0x3b, 0x3b, 0x20, 0x6d, 0x75, 0x63, 0x68, 0x61, 0x5f, 0x61, 0x70, 0x70, 0x20, 0x90, 0xdd,
  0x92, 0xe8, 0x0d, 0x0a, 0x61, 0x70, 0x70, 0x63, 0x66, 0x67, 0x2d, 0x6c, 0x6f, 0x67, 0x66, 0x69,
  0x6c, 0x65, 0x3d, 0x6d, 0x75, 0x63, 0x68, 0x61, 0x61, 0x70, 0x70, 0x2e, 0x6c, 0x6f, 0x67, 0x0d,
  0x0a, 0x61, 0x70, 0x70, 0x63, 0x66, 0x67, 0x2d, 0x6c, 0x6f, 0x67, 0x6c, 0x65, 0x76, 0x65, 0x6c,
  0x3d, 0x49, 0x4e, 0x46, 0x4f, 0x0d, 0x0a, 0x0d, 0x0a, 0x5b, 0x4d, 0x75, 0x63, 0x68, 0x61, 0x53,
  0x79, 0x73, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x5d, 0x0d, 0x0a, 0x3b, 0x3b, 0x20, 0x4d, 0x55,
  0x43, 0x48, 0x41, 0x20, 0x83, 0x56, 0x83, 0x58, 0x83, 0x65, 0x83, 0x80, 0x90, 0xdd, 0x92, 0xe8,
  0x0d, 0x0a, 0x73, 0x79, 0x73, 0x63, 0x66, 0x67, 0x2d, 0x64, 0x61, 0x65, 0x6d, 0x6f, 0x6e, 0x5f,
  0x65, 0x78, 0x65, 0x3d, 0x2e, 0x5c, 0x4d, 0x75, 0x63, 0x68, 0x61, 0x42, 0x69, 0x6e, 0x5c, 0x6d,
  0x75, 0x63, 0x68, 0x61, 0x63, 0x64, 0x2e, 0x65, 0x78, 0x65, 0x0d, 0x0a, 0x73, 0x79, 0x73, 0x63,
  0x66, 0x67, 0x2d, 0x64, 0x61, 0x65, 0x6d, 0x6f, 0x6e, 0x5f, 0x70, 0x69, 0x64, 0x66, 0x69, 0x6c,
  0x65, 0x3d, 0x6d, 0x75, 0x63, 0x68, 0x61, 0x63, 0x64, 0x2e, 0x70, 0x69, 0x64, 0x0d, 0x0a, 0x73,
  0x79, 0x73, 0x63, 0x66, 0x67, 0x2d, 0x64, 0x61, 0x65, 0x6d, 0x6f, 0x6e, 0x5f, 0x6c, 0x6f, 0x67,
  0x66, 0x69, 0x6c, 0x65, 0x3d, 0x6d, 0x75, 0x63, 0x68, 0x61, 0x63, 0x64, 0x2e, 0x6c, 0x6f, 0x67,
  0x0d, 0x0a, 0x73, 0x79, 0x73, 0x63, 0x66, 0x67, 0x2d, 0x64, 0x61, 0x65, 0x6d, 0x6f, 0x6e, 0x5f,
  0x6c, 0x6f, 0x67, 0x6c, 0x65, 0x76, 0x65, 0x6c, 0x3d, 0x49, 0x4e, 0x46, 0x4f, 0x0d, 0x0a, 0x73,
  0x79, 0x73, 0x63, 0x66, 0x67, 0x2d, 0x64, 0x61, 0x65, 0x6d, 0x6f, 0x6e, 0x5f, 0x6c, 0x69, 0x73,
  0x74, 0x65, 0x6e, 0x3d, 0x74, 0x63, 0x70, 0x3a, 0x30, 0x2e, 0x30, 0x2e, 0x30, 0x2e, 0x30, 0x3a,
  0x31, 0x32, 0x33, 0x34, 0x35, 0x0d, 0x0a, 0x73, 0x79, 0x73, 0x63, 0x66, 0x67, 0x2d, 0x63, 0x6c,
  0x69, 0x65, 0x6e, 0x74, 0x5f, 0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x3d, 0x74, 0x63, 0x70,
  0x3a, 0x31, 0x32, 0x37, 0x2e, 0x30, 0x2e, 0x30, 0x2e, 0x31, 0x3a, 0x31, 0x32, 0x33, 0x34, 0x35,
  0x0d, 0x0a, 0x0d, 0x0a, 0x5b, 0x4d, 0x75, 0x63, 0x68, 0x61, 0x43, 0x41, 0x43, 0x6f, 0x6e, 0x66,
  0x69, 0x67, 0x5d, 0x0d, 0x0a, 0x3b, 0x3b, 0x20, 0x4d, 0x55, 0x43, 0x48, 0x41, 0x20, 0x94, 0x46,
  0x8f, 0xd8, 0x90, 0xdd, 0x92, 0xe8, 0x0d, 0x0a, 0x63, 0x61, 0x63, 0x66, 0x67, 0x2d, 0x67, 0x61,
  0x6d, 0x65, 0x5f, 0x63, 0x64, 0x3d, 0x57, 0x4d, 0x36, 0x31, 0x0d, 0x0a, 0x63, 0x61, 0x63, 0x66,
  0x67, 0x2d, 0x67, 0x61, 0x6d, 0x65, 0x5f, 0x76, 0x65, 0x72, 0x3d, 0x30, 0x33, 0x2e, 0x30, 0x34,
  0x0d, 0x0a, 0x63, 0x61, 0x63, 0x66, 0x67, 0x2d, 0x67, 0x61, 0x6d, 0x65, 0x5f, 0x62, 0x6f, 0x61,
  0x72, 0x64, 0x5f, 0x74, 0x79, 0x70, 0x65, 0x3d, 0x30, 0x0d, 0x0a, 0x63, 0x61, 0x63, 0x66, 0x67,
  0x2d, 0x67, 0x61, 0x6d, 0x65, 0x5f, 0x62, 0x6f, 0x61, 0x72, 0x64, 0x5f, 0x69, 0x64, 0x3d, 0x57,
  0x4d, 0x36, 0x0d, 0x0a, 0x63, 0x61, 0x63, 0x66, 0x67, 0x2d, 0x61, 0x75, 0x74, 0x68, 0x5f, 0x73,
  0x65, 0x72, 0x76, 0x65, 0x72, 0x5f, 0x75, 0x72, 0x6c, 0x3d, 0x68, 0x74, 0x74, 0x70, 0x73, 0x3a,
  0x2f, 0x2f, 0x31, 0x36, 0x37, 0x2e, 0x37, 0x31, 0x2e, 0x36, 0x33, 0x2e, 0x36, 0x31, 0x3a, 0x31,
  0x30, 0x30, 0x38, 0x32, 0x2f, 0x0d, 0x0a, 0x63, 0x61, 0x63, 0x66, 0x67, 0x2d, 0x61, 0x75, 0x74,
  0x68, 0x5f, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 0x5f, 0x73, 0x73, 0x6c, 0x76, 0x65, 0x72, 0x69,
  0x66, 0x79, 0x3d, 0x30, 0x0d, 0x0a, 0x63, 0x61, 0x63, 0x66, 0x67, 0x2d, 0x61, 0x75, 0x74, 0x68,
  0x5f, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 0x5f, 0x73, 0x73, 0x6c, 0x63, 0x61, 0x66, 0x69, 0x6c,
  0x65, 0x3d, 0x2e, 0x5c, 0x66, 0x72, 0x6f, 0x6e, 0x74, 0x2e, 0x6d, 0x75, 0x63, 0x68, 0x61, 0x2d,
  0x70, 0x72, 0x64, 0x2e, 0x6e, 0x62, 0x67, 0x69, 0x2d, 0x61, 0x6d, 0x6e, 0x65, 0x74, 0x2e, 0x6a,
  0x70, 0x2e, 0x63, 0x61, 0x63, 0x65, 0x72, 0x74, 0x2e, 0x70, 0x65, 0x6d, 0x0d, 0x0a, 0x63, 0x61,
  0x63, 0x66, 0x67, 0x2d, 0x61, 0x75, 0x74, 0x68, 0x5f, 0x73, 0x65, 0x72, 0x76, 0x65, 0x72, 0x5f,
  0x74, 0x69, 0x6d, 0x65, 0x6f, 0x75, 0x74, 0x3d, 0x33, 0x30, 0x30, 0x0d, 0x0a, 0x63, 0x61, 0x63,
  0x66, 0x67, 0x2d, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x5f, 0x61, 0x69, 0x6e, 0x66,
  0x6f, 0x5f, 0x72, 0x65, 0x6e, 0x65, 0x77, 0x3d, 0x31, 0x38, 0x30, 0x30, 0x0d, 0x0a, 0x63, 0x61,
  0x63, 0x66, 0x67, 0x2d, 0x69, 0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x5f, 0x61, 0x69, 0x6e,
  0x66, 0x6f, 0x5f, 0x72, 0x65, 0x74, 0x72, 0x79, 0x3d, 0x36, 0x30, 0x0d, 0x0a, 0x0d, 0x0a, 0x5b,
  0x4d, 0x75, 0x63, 0x68, 0x61, 0x44, 0x74, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x5d, 0x0d, 0x0a,
  0x3b, 0x3b, 0x20, 0x4d, 0x55, 0x43, 0x48, 0x41, 0x20, 0x83, 0x74, 0x83, 0x40, 0x83, 0x43, 0x83,
  0x8b, 0x94, 0x7a, 0x90, 0x4d, 0x20, 0x28, 0x44, 0x54, 0x29, 0x20, 0x90, 0xdd, 0x92, 0xe8, 0x0d,
  0x0a, 0x64, 0x74, 0x63, 0x66, 0x67, 0x2d, 0x64, 0x6c, 0x5f, 0x70, 0x72, 0x6f, 0x64, 0x75, 0x63,
  0x74, 0x5f, 0x69, 0x64, 0x3d, 0x30, 0x78, 0x35, 0x37, 0x34, 0x64, 0x33, 0x36, 0x33, 0x31, 0x0d,
  0x0a, 0x64, 0x74, 0x63, 0x66, 0x67, 0x2d, 0x64, 0x6c, 0x5f, 0x63, 0x68, 0x75, 0x6e, 0x6b, 0x5f,
  0x73, 0x69, 0x7a, 0x65, 0x3d, 0x30, 0x78, 0x31, 0x30, 0x30, 0x30, 0x30, 0x0d, 0x0a, 0x64, 0x74,
  0x63, 0x66, 0x67, 0x2d, 0x64, 0x6c, 0x5f, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x5f, 0x70, 0x61, 0x74,
  0x68, 0x3d, 0x64, 0x6c, 0x5f, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x0d, 0x0a, 0x64, 0x74, 0x63, 0x66,
  0x67, 0x2d, 0x64, 0x6c, 0x5f, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x5f, 0x73, 0x69, 0x7a, 0x65, 0x3d,
  0x30, 0x0d, 0x0a, 0x64, 0x74, 0x63, 0x66, 0x67, 0x2d, 0x64, 0x6c, 0x5f, 0x69, 0x6d, 0x61, 0x67,
  0x65, 0x5f, 0x74, 0x79, 0x70, 0x65, 0x3d, 0x46, 0x49, 0x4c, 0x45, 0x0d, 0x0a, 0x64, 0x74, 0x63,
  0x66, 0x67, 0x2d, 0x64, 0x6c, 0x5f, 0x69, 0x6d, 0x61, 0x67, 0x65, 0x5f, 0x63, 0x72, 0x79, 0x70,
  0x74, 0x5f, 0x6b, 0x65, 0x79, 0x3d, 0x30, 0x78, 0x64, 0x64, 0x31, 0x34, 0x39, 0x61, 0x62, 0x61,
  0x0d, 0x0a, 0x64, 0x74, 0x63, 0x66, 0x67, 0x2d, 0x64, 0x6c, 0x5f, 0x6c, 0x6f, 0x67, 0x5f, 0x6c,
  0x65, 0x76, 0x65, 0x6c, 0x3d, 0x49, 0x4e, 0x46, 0x4f, 0x0d, 0x0a, 0x64, 0x74, 0x63, 0x66, 0x67,
  0x2d, 0x64, 0x6c, 0x5f, 0x6c, 0x61, 0x6e, 0x5f, 0x63, 0x72, 0x79, 0x70, 0x74, 0x5f, 0x6b, 0x65,
  0x79, 0x3d, 0x30, 0x78, 0x62, 0x39, 0x34, 0x62, 0x61, 0x39, 0x66, 0x64, 0x31, 0x35, 0x32, 0x35,
  0x38, 0x62, 0x63, 0x62, 0x0d, 0x0a, 0x64, 0x74, 0x63, 0x66, 0x67, 0x2d, 0x64, 0x6c, 0x5f, 0x6c,
  0x61, 0x6e, 0x5f, 0x62, 0x72, 0x6f, 0x61, 0x64, 0x63, 0x61, 0x73, 0x74, 0x5f, 0x69, 0x6e, 0x74,
  0x65, 0x72, 0x76, 0x61, 0x6c, 0x3d, 0x31, 0x30, 0x30, 0x30, 0x0d, 0x0a, 0x64, 0x74, 0x63, 0x66,
  0x67, 0x2d, 0x64, 0x6c, 0x5f, 0x6c, 0x61, 0x6e, 0x5f, 0x75, 0x64, 0x70, 0x5f, 0x70, 0x6f, 0x72,
  0x74, 0x3d, 0x38, 0x37, 0x36, 0x35, 0x0d, 0x0a, 0x64, 0x74, 0x63, 0x66, 0x67, 0x2d, 0x64, 0x6c,
  0x5f, 0x6c, 0x61, 0x6e, 0x5f, 0x62, 0x61, 0x6e, 0x64, 0x77, 0x69, 0x64, 0x74, 0x68, 0x5f, 0x6c,
  0x69, 0x6d, 0x69, 0x74, 0x3d, 0x30, 0x0d, 0x0a, 0x64, 0x74, 0x63, 0x66, 0x67, 0x2d, 0x64, 0x6c,
  0x5f, 0x6c, 0x61, 0x6e, 0x5f, 0x62, 0x72, 0x6f, 0x61, 0x64, 0x63, 0x61, 0x73, 0x74, 0x5f, 0x61,
  0x64, 0x64, 0x72, 0x65, 0x73, 0x73, 0x3d, 0x30, 0x2e, 0x30, 0x2e, 0x30, 0x2e, 0x30, 0x0d, 0x0a,
  0x64, 0x74, 0x63, 0x66, 0x67, 0x2d, 0x64, 0x6c, 0x5f, 0x77, 0x61, 0x6e, 0x5f, 0x72, 0x65, 0x74,
  0x72, 0x79, 0x5f, 0x6c, 0x69, 0x6d, 0x69, 0x74, 0x3d, 0x0d, 0x0a, 0x64, 0x74, 0x63, 0x66, 0x67,
  0x2d, 0x64, 0x6c, 0x5f, 0x77, 0x61, 0x6e, 0x5f, 0x72, 0x65, 0x74, 0x72, 0x79, 0x5f, 0x69, 0x6e,
  0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x3d, 0x0d, 0x0a, 0x64, 0x74, 0x63, 0x66, 0x67, 0x2d, 0x64,
  0x6c, 0x5f, 0x77, 0x61, 0x6e, 0x5f, 0x73, 0x65, 0x6e, 0x64, 0x5f, 0x74, 0x69, 0x6d, 0x65, 0x6f,
  0x75, 0x74, 0x3d, 0x0d, 0x0a, 0x64, 0x74, 0x63, 0x66, 0x67, 0x2d, 0x64, 0x6c, 0x5f, 0x77, 0x61,
  0x6e, 0x5f, 0x72, 0x65, 0x63, 0x76, 0x5f, 0x74, 0x69, 0x6d, 0x65, 0x6f, 0x75, 0x74, 0x3d, 0x0d,
  0x0a, 0x64, 0x74, 0x63, 0x66, 0x67, 0x2d, 0x64, 0x6c, 0x5f, 0x6c, 0x61, 0x6e, 0x5f, 0x72, 0x65,
  0x74, 0x72, 0x79, 0x5f, 0x6c, 0x69, 0x6d, 0x69, 0x74, 0x3d, 0x0d, 0x0a, 0x64, 0x74, 0x63, 0x66,
  0x67, 0x2d, 0x64, 0x6c, 0x5f, 0x6c, 0x61, 0x6e, 0x5f, 0x72, 0x65, 0x74, 0x72, 0x79, 0x5f, 0x69,
  0x6e, 0x74, 0x65, 0x72, 0x76, 0x61, 0x6c, 0x3d, 0x0d, 0x0a, 0x64, 0x74, 0x63, 0x66, 0x67, 0x2d,
  0x64, 0x6c, 0x5f, 0x6c, 0x61, 0x6e, 0x5f, 0x73, 0x65, 0x6e, 0x64, 0x5f, 0x74, 0x69, 0x6d, 0x65,
  0x6f, 0x75, 0x74, 0x3d, 0x0d, 0x0a, 0x64, 0x74, 0x63, 0x66, 0x67, 0x2d, 0x64, 0x6c, 0x5f, 0x6c,
  0x61, 0x6e, 0x5f, 0x72, 0x65, 0x63, 0x76, 0x5f, 0x74, 0x69, 0x6d, 0x65, 0x6f, 0x75, 0x74, 0x3d,
  0x0d, 0x0a, 0x0d, 0x0a, 0x5b, 0x4d, 0x75, 0x63, 0x68, 0x61, 0x44, 0x74, 0x4d, 0x6f, 0x64, 0x65,
  0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x5d, 0x0d, 0x0a, 0x3b, 0x3b, 0x20, 0x4d, 0x55, 0x43, 0x48,
  0x41, 0x20, 0x83, 0x74, 0x83, 0x40, 0x83, 0x43, 0x83, 0x8b, 0x94, 0x7a, 0x90, 0x4d, 0x83, 0x82,
  0x81, 0x5b, 0x83, 0x68, 0x90, 0xdd, 0x92, 0xe8, 0x0d, 0x0a, 0x64, 0x74, 0x6d, 0x6f, 0x64, 0x65,
  0x2d, 0x69, 0x6f, 0x5f, 0x64, 0x69, 0x72, 0x3d, 0x2e, 0x5c, 0x0d, 0x0a, 0x64, 0x74, 0x6d, 0x6f,
  0x64, 0x65, 0x2d, 0x69, 0x6f, 0x5f, 0x66, 0x69, 0x6c, 0x65, 0x3d, 0x57, 0x4d, 0x36, 0x31, 0x30,
  0x4a, 0x50, 0x4e, 0x0d, 0x0a, 0x64, 0x74, 0x6d, 0x6f, 0x64, 0x65, 0x2d, 0x69, 0x6f, 0x5f, 0x63,
  0x6f, 0x6e, 0x76, 0x3d, 0x44, 0x45, 0x43, 0x45, 0x58, 0x50, 0x0d, 0x0a, 0x64, 0x74, 0x6d, 0x6f,
  0x64, 0x65, 0x2d, 0x69, 0x6f, 0x5f, 0x70, 0x61, 0x73, 0x73, 0x70, 0x68, 0x72, 0x61, 0x73, 0x65,
  0x3d, 0x51, 0x78, 0x38, 0x68, 0x4a, 0x31, 0x4b, 0x69, 0x6c, 0x77, 0x65, 0x41, 0x70, 0x35, 0x58,
  0x6d, 0x0d, 0x0a
};

static const unsigned char WritableConfig[] = {
  0x5b, 0x52, 0x75, 0x6e, 0x74, 0x69, 0x6d, 0x65, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x5d, 0x0d,
  0x0a, 0x6d, 0x6f, 0x64, 0x65, 0x3d, 0x0d, 0x0a, 0x6e, 0x65, 0x74, 0x49, 0x44, 0x3d, 0x31, 0x32,
  0x33, 0x34, 0x0d, 0x0a, 0x73, 0x65, 0x72, 0x69, 0x61, 0x6c, 0x49, 0x44, 0x3d, 0x32, 0x38, 0x30,
  0x38, 0x31, 0x31, 0x39, 0x39, 0x30, 0x30, 0x30, 0x32
};

linb::ini myconfig;

static char gatewayAddressStr[256];

bool (WINAPI* orig_SetSystemTime)(const SYSTEMTIME* lpSystemTime);

static bool SetSystemTimeHook(const SYSTEMTIME *lpSystemTime)
{
	return 1;
}

u_short(PASCAL FAR* htons_orig)(u_short hostshort);

static u_short htonsHook(u_short hostshort)
{
#if _DEBUG
	info("htons: %i", hostshort);
#endif

	if (hostshort == 80) {
#ifdef _DEBUG
		info("replacing port...");
#endif
		return htons_orig(HttpPort);
	}
	else {
		return htons_orig(hostshort);
	}
}

int(WSAAPI* g_origgetaddrinfoo)(PCSTR pNodeName, PCSTR pServiceName, const ADDRINFOA* pHints, PADDRINFOA* ppResult);

int WSAAPI getaddrinfoHookAMAuth(PCSTR pNodeName, PCSTR pServiceName, const ADDRINFOA* pHints, PADDRINFOA* ppResult)
{
#if _DEBUG
	info("getaddrinfo: %s, %s", pNodeName, pServiceName);
#endif
	if (strcmp(pNodeName, "tenporouter.loc") == 0)
	{
		return g_origgetaddrinfoo(config["Network"]["RouterIP"].c_str(), pServiceName, pHints, ppResult);
	}
	else if (strcmp(pNodeName, "bbrouter.loc") == 0)
	{
		return g_origgetaddrinfoo(config["Network"]["RouterIP"].c_str(), pServiceName, pHints, ppResult);
	}
	else if (strcmp(pNodeName, "naominet.jp") == 0)
	{
		return g_origgetaddrinfoo("teknoparrot.xyz", pServiceName, pHints, ppResult);
	}
	else {
		return g_origgetaddrinfoo(pNodeName, pServiceName, pHints, ppResult);
	}
}

static int WINAPI GetRTTAndHopCountStubAM(_In_ uint32_t DestIpAddress, _Out_ PULONG HopCount, _In_ ULONG MaxHops, _Out_ PULONG RTT)
{
	return 1;
}

static void prepareWMMT()
{
	if (FILE* file = fopen("AMConfig.ini.orig", "r")) {
		fclose(file);
	}
	else {
		MoveFile(L"AMConfig.ini", L"AMConfig.ini.orig");
		FILE* file2 = fopen("AMConfig.ini", "wb");
		fwrite(AMConfig, 1, sizeof(AMConfig), file2);
		fclose(file2);
	}

	if (FILE* wc = fopen("WritableConfig.ini", "r"))
	{
		fclose(wc);
		return;
	}
	else
	{
		FILE* writecon = fopen("WritableConfig.ini", "wb");
		fwrite(WritableConfig, 1, sizeof(WritableConfig), writecon);
		fclose(writecon);
		return;
	}
}

typedef HRESULT(__stdcall* DllRegisterServerFunc)();

static void dllreg()
{
	//iauthdll.dll
	HMODULE hModule = LoadLibrary(L"iauthdll.dll");
	DllRegisterServerFunc DllRegisterServer = (DllRegisterServerFunc)GetProcAddress(hModule, "DllRegisterServer");
	HRESULT hr = DllRegisterServer();
	if (SUCCEEDED(hr))
	{
#ifdef DEBUG
		īnfo(true, "iauthdll.dll registered successfully!");
#endif
	}
	else
	{
		int msgboxID = MessageBox(
			NULL,
			(LPCWSTR)L"There was an error registering a DLL needed for WMMT6 online.",
			(LPCWSTR)L"WMMT6 Banapass Setup",
			MB_ICONWARNING | MB_OK
		);
		// There was an error
	}
}

static InitFunction HookAmAuthD64([]()
	{
	// write config files for mt6
		prepareWMMT();
		dllreg();
		MH_Initialize();
		MH_CreateHookApi(L"kernel32.dll", "SetSystemTime", SetSystemTimeHook, (void**)&orig_SetSystemTime);
		MH_CreateHookApi(L"ws2_32.dll", "getaddrinfo", getaddrinfoHookAMAuth, (void**)&g_origgetaddrinfoo);
		MH_CreateHookApi(L"ws2_32.dll", "htons", htonsHook, (void**)&htons_orig);
		MH_CreateHookApi(L"iphlpapi.dll", "GetRTTAndHopCount", GetRTTAndHopCountStubAM, NULL);
		MH_EnableHook(MH_ALL_HOOKS);
	}, GameID::AmAuthD64);
#pragma optimize("", on)
#endif