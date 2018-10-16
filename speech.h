// Talkie library
// Copyright 2011 Peter Knight
// This code is released under GPLv2 license.
//
// The following phrases are derived from VM61002 ROM
//
// A male voice with a US accent.
//
// These phrases have a very military bias
// with lots of very useful engineering words.
// They also have good expression.
//

#include <Adafruit_CircuitPlayground.h>
#include <SPI.h>
#include <Wire.h>

const uint8_t spZERO[] PROGMEM = {
    0x69, 0xFB, 0x59, 0xDD, 0x51, 0xD5, 0xD7, 0xB5, 0x6F, 0x0A, 0x78,
    0xC0, 0x52, 0x01, 0x0F, 0x50, 0xAC, 0xF6, 0xA8, 0x16, 0x15, 0xF2,
    0x7B, 0xEA, 0x19, 0x47, 0xD0, 0x64, 0xEB, 0xAD, 0x76, 0xB5, 0xEB,
    0xD1, 0x96, 0x24, 0x6E, 0x62, 0x6D, 0x5B, 0x1F, 0x0A, 0xA7, 0xB9,
    0xC5, 0xAB, 0xFD, 0x1A, 0x62, 0xF0, 0xF0, 0xE2, 0x6C, 0x73, 0x1C,
    0x73, 0x52, 0x1D, 0x19, 0x94, 0x6F, 0xCE, 0x7D, 0xED, 0x6B, 0xD9,
    0x82, 0xDC, 0x48, 0xC7, 0x2E, 0x71, 0x8B, 0xBB, 0xDF, 0xFF, 0x1F};
const uint8_t spFOUR[] PROGMEM = {
    0x08, 0x68, 0x21, 0x0D, 0x03, 0x04, 0x28, 0xCE, 0x92, 0x03, 0x23,
    0x4A, 0xCA, 0xA6, 0x1C, 0xDA, 0xAD, 0xB4, 0x70, 0xED, 0x19, 0x64,
    0xB7, 0xD3, 0x91, 0x45, 0x51, 0x35, 0x89, 0xEA, 0x66, 0xDE, 0xEA,
    0xE0, 0xAB, 0xD3, 0x29, 0x4F, 0x1F, 0xFA, 0x52, 0xF6, 0x90, 0x52,
    0x3B, 0x25, 0x7F, 0xDD, 0xCB, 0x9D, 0x72, 0x72, 0x8C, 0x79, 0xCB,
    0x6F, 0xFA, 0xD2, 0x10, 0x9E, 0xB4, 0x2C, 0xE1, 0x4F, 0x25, 0x70,
    0x3A, 0xDC, 0xBA, 0x2F, 0x6F, 0xC1, 0x75, 0xCB, 0xF2, 0xFF};
const uint8_t spEIGHT[] PROGMEM = {
    0x65, 0x69, 0x89, 0xC5, 0x73, 0x66, 0xDF, 0xE9, 0x8C, 0x33, 0x0E,
    0x41, 0xC6, 0xEA, 0x5B, 0xEF, 0x7A, 0xF5, 0x33, 0x25, 0x50, 0xE5,
    0xEA, 0x39, 0xD7, 0xC5, 0x6E, 0x08, 0x14, 0xC1, 0xDD, 0x45, 0x64,
    0x03, 0x00, 0x80, 0x00, 0xAE, 0x70, 0x33, 0xC0, 0x73, 0x33, 0x1A,
    0x10, 0x40, 0x8F, 0x2B, 0x14, 0xF8, 0x7F};
const uint8_t spONE[] PROGMEM = {
    0x66, 0x4E, 0xA8, 0x7A, 0x8D, 0xED, 0xC4, 0xB5, 0xCD, 0x89, 0xD4, 0xBC,
    0xA2, 0xDB, 0xD1, 0x27, 0xBE, 0x33, 0x4C, 0xD9, 0x4F, 0x9B, 0x4D, 0x57,
    0x8A, 0x76, 0xBE, 0xF5, 0xA9, 0xAA, 0x2E, 0x4F, 0xD5, 0xCD, 0xB7, 0xD9,
    0x43, 0x5B, 0x87, 0x13, 0x4C, 0x0D, 0xA7, 0x75, 0xAB, 0x7B, 0x3E, 0xE3,
    0x19, 0x6F, 0x7F, 0xA7, 0xA7, 0xF9, 0xD0, 0x30, 0x5B, 0x1D, 0x9E, 0x9A,
    0x34, 0x44, 0xBC, 0xB6, 0x7D, 0xFE, 0x1F};
const uint8_t spFIVE[] PROGMEM = {
    0x08, 0x68, 0x4E, 0x9D, 0x02, 0x1C, 0x60, 0xC0, 0x8C, 0x69, 0x12, 0xB0,
    0xC0, 0x28, 0xAB, 0x8C, 0x9C, 0xC0, 0x2D, 0xBB, 0x38, 0x79, 0x31, 0x15,
    0xA3, 0xB6, 0xE4, 0x16, 0xB7, 0xDC, 0xF5, 0x6E, 0x57, 0xDF, 0x54, 0x5B,
    0x85, 0xBE, 0xD9, 0xE3, 0x5C, 0xC6, 0xD6, 0x6D, 0xB1, 0xA5, 0xBF, 0x99,
    0x5B, 0x3B, 0x5A, 0x30, 0x09, 0xAF, 0x2F, 0xED, 0xEC, 0x31, 0xC4, 0x5C,
    0xBE, 0xD6, 0x33, 0xDD, 0xAD, 0x88, 0x87, 0xE2, 0xD2, 0xF2, 0xF4, 0xE0,
    0x16, 0x2A, 0xB2, 0xE3, 0x63, 0x1F, 0xF9, 0xF0, 0xE7, 0xFF, 0x01};
const uint8_t spNINE[] PROGMEM = {
    0xE6, 0xA8, 0x1A, 0x35, 0x5D, 0xD6, 0x9A, 0x35, 0x4B, 0x8C, 0x4E,
    0x6B, 0x1A, 0xD6, 0xA6, 0x51, 0xB2, 0xB5, 0xEE, 0x58, 0x9A, 0x13,
    0x4F, 0xB5, 0x35, 0x67, 0x68, 0x26, 0x3D, 0x4D, 0x97, 0x9C, 0xBE,
    0xC9, 0x75, 0x2F, 0x6D, 0x7B, 0xBB, 0x5B, 0xDF, 0xFA, 0x36, 0xA7,
    0xEF, 0xBA, 0x25, 0xDA, 0x16, 0xDF, 0x69, 0xAC, 0x23, 0x05, 0x45,
    0xF9, 0xAC, 0xB9, 0x8F, 0xA3, 0x97, 0x20, 0x73, 0x9F, 0x54, 0xCE,
    0x1E, 0x45, 0xC2, 0xA2, 0x4E, 0x3E, 0xD3, 0xD5, 0x3D, 0xB1, 0x79,
    0x24, 0x0D, 0xD7, 0x48, 0x4C, 0x6E, 0xE1, 0x2C, 0xDE, 0xFF, 0x0F};
const uint8_t spTWO[] PROGMEM = {
    0x06, 0xB8, 0x59, 0x34, 0x00, 0x27, 0xD6, 0x38, 0x60, 0x58, 0xD3,
    0x91, 0x55, 0x2D, 0xAA, 0x65, 0x9D, 0x4F, 0xD1, 0xB8, 0x39, 0x17,
    0x67, 0xBF, 0xC5, 0xAE, 0x5A, 0x1D, 0xB5, 0x7A, 0x06, 0xF6, 0xA9,
    0x7D, 0x9D, 0xD2, 0x6C, 0x55, 0xA5, 0x26, 0x75, 0xC9, 0x9B, 0xDF,
    0xFC, 0x6E, 0x0E, 0x63, 0x3A, 0x34, 0x70, 0xAF, 0x3E, 0xFF, 0x1F};
const uint8_t spSIX[] PROGMEM = {
    0x04, 0xF8, 0xAD, 0x4C, 0x02, 0x16, 0xB0, 0x80, 0x06, 0x56,
    0x35, 0x5D, 0xA8, 0x2A, 0x6D, 0xB9, 0xCD, 0x69, 0xBB, 0x2B,
    0x55, 0xB5, 0x2D, 0xB7, 0xDB, 0xFD, 0x9C, 0x0D, 0xD8, 0x32,
    0x8A, 0x7B, 0xBC, 0x02, 0x00, 0x03, 0x0C, 0xB1, 0x2E, 0x80,
    0xDF, 0xD2, 0x35, 0x20, 0x01, 0x0E, 0x60, 0xE0, 0xFF, 0x01};
const uint8_t spTEN[] PROGMEM = {
    0x0E, 0x38, 0x3C, 0x2D, 0x00, 0x5F, 0xB6, 0x19, 0x60, 0xA8, 0x90,
    0x93, 0x36, 0x2B, 0xE2, 0x99, 0xB3, 0x4E, 0xD9, 0x7D, 0x89, 0x85,
    0x2F, 0xBE, 0xD5, 0xAD, 0x4F, 0x3F, 0x64, 0xAB, 0xA4, 0x3E, 0xBA,
    0xD3, 0x59, 0x9A, 0x2E, 0x75, 0xD5, 0x39, 0x6D, 0x6B, 0x0A, 0x2D,
    0x3C, 0xEC, 0xE5, 0xDD, 0x1F, 0xFE, 0xB0, 0xE7, 0xFF, 0x03};
const uint8_t spTHREE[] PROGMEM = {
    0x0C, 0xE8, 0x2E, 0x94, 0x01, 0x4D, 0xBA, 0x4A, 0x40, 0x03, 0x16,
    0x68, 0x69, 0x36, 0x1C, 0xE9, 0xBA, 0xB8, 0xE5, 0x39, 0x70, 0x72,
    0x84, 0xDB, 0x51, 0xA4, 0xA8, 0x4E, 0xA3, 0xC9, 0x77, 0xB1, 0xCA,
    0xD6, 0x52, 0xA8, 0x71, 0xED, 0x2A, 0x7B, 0x4B, 0xA6, 0xE0, 0x37,
    0xB7, 0x5A, 0xDD, 0x48, 0x8E, 0x94, 0xF1, 0x64, 0xCE, 0x6D, 0x19,
    0x55, 0x91, 0xBC, 0x6E, 0xD7, 0xAD, 0x1E, 0xF5, 0xAA, 0x77, 0x7A,
    0xC6, 0x70, 0x22, 0xCD, 0xC7, 0xF9, 0x89, 0xCF, 0xFF, 0x03};
const uint8_t spSEVEN[] PROGMEM = {
    0x0C, 0xF8, 0x5E, 0x4C, 0x01, 0xBF, 0x95, 0x7B, 0xC0, 0x02, 0x16,
    0xB0, 0xC0, 0xC8, 0xBA, 0x36, 0x4D, 0xB7, 0x27, 0x37, 0xBB, 0xC5,
    0x29, 0xBA, 0x71, 0x6D, 0xB7, 0xB5, 0xAB, 0xA8, 0xCE, 0xBD, 0xD4,
    0xDE, 0xA6, 0xB2, 0x5A, 0xB1, 0x34, 0x6A, 0x1D, 0xA7, 0x35, 0x37,
    0xE5, 0x5A, 0xAE, 0x6B, 0xEE, 0xD2, 0xB6, 0x26, 0x4C, 0x37, 0xF5,
    0x4D, 0xB9, 0x9A, 0x34, 0x39, 0xB7, 0xC6, 0xE1, 0x1E, 0x81, 0xD8,
    0xA2, 0xEC, 0xE6, 0xC7, 0x7F, 0xFE, 0xFB, 0x7F};
const uint8_t spA[] PROGMEM = {
    0x65, 0x2C, 0x96, 0xAD, 0x7B, 0x6A, 0x9F, 0x66, 0xE4, 0x20, 0x8D, 0x9C,
    0x73, 0xAB, 0x5B, 0xDC, 0xE2, 0x96, 0xB7, 0xBA, 0xF5, 0x6A, 0x66, 0x28,
    0xA0, 0xCE, 0xD5, 0xBB, 0xDB, 0xFD, 0x1E, 0xE6, 0x38, 0xA7, 0x36, 0xCF,
    0x9C, 0x80, 0x51, 0x8B, 0xEB, 0x52, 0xD7, 0xBC, 0xFF, 0x3F};
const uint8_t spB[] PROGMEM = {
    0xA6, 0x2F, 0xAA, 0x05, 0x5C, 0xD6, 0x8C, 0xBC, 0xC7, 0x16,
    0x70, 0x59, 0x33, 0xB2, 0x95, 0x0B, 0xC1, 0xFD, 0xCD, 0xCC,
    0x66, 0x3A, 0xF3, 0x51, 0xAD, 0x98, 0x00, 0x55, 0x8B, 0x67,
    0xDB, 0xC7, 0x3E, 0xD5, 0xAD, 0xEE, 0x75, 0x2F, 0xE7, 0x2C,
    0x4D, 0x60, 0xBE, 0x26, 0xDF, 0xF1, 0x89, 0xEF, 0xFF, 0x03};
const uint8_t spC[] PROGMEM = {
    0x04, 0xF8, 0xA5, 0x83, 0x03, 0x12, 0xB0, 0x80, 0x07, 0x22, 0xB0,
    0xC2, 0xEE, 0x8D, 0x45, 0x7D, 0xC9, 0xCA, 0x67, 0x29, 0x42, 0xF5,
    0x35, 0x3B, 0xDF, 0xF9, 0x28, 0x66, 0x0D, 0x40, 0xCF, 0xD7, 0xB3,
    0x1C, 0xCD, 0xAC, 0x06, 0x14, 0xB5, 0x68, 0x0E, 0x7D, 0xEE, 0x4B,
    0xDF, 0xD2, 0x39, 0x5B, 0x02, 0x44, 0xBD, 0xCE, 0x57, 0xBE, 0xF2,
    0x9D, 0xEE, 0x55, 0x0A, 0xC1, 0x73, 0x4D, 0x7E, 0xF2, 0xF3, 0xFF};
const uint8_t spD[] PROGMEM = {
    0x06, 0x98, 0x30, 0x68, 0xE4, 0x6B, 0x84, 0xA0, 0xE8, 0xD3, 0x93,
    0x8D, 0xEC, 0x84, 0x9E, 0x4B, 0x6E, 0x36, 0x8A, 0x19, 0x0D, 0xA8,
    0xEA, 0x71, 0xAF, 0x7A, 0xDF, 0xE7, 0xB2, 0xAD, 0xE0, 0x00, 0xD3,
    0x8B, 0xEB, 0x9E, 0x8F, 0x7C, 0xA6, 0x73, 0xE5, 0x40, 0xA8, 0x5A,
    0x1C, 0xAF, 0x78, 0xC5, 0xDB, 0xDF, 0xFF, 0x0F};
const uint8_t spE[] PROGMEM = {
    0xA2, 0x59, 0x95, 0x51, 0xBA, 0x17, 0xF7, 0x6A, 0x95, 0xAB, 0x38,
    0x42, 0xE4, 0x92, 0x5D, 0xEE, 0x62, 0x15, 0x33, 0x3B, 0x50, 0xD6,
    0x92, 0x5D, 0xAE, 0x6A, 0xC5, 0x04, 0xA8, 0x5A, 0xBC, 0xEB, 0xDD,
    0xEC, 0x76, 0x77, 0xBB, 0xDF, 0xD3, 0x9E, 0xF6, 0x32, 0x97, 0xBE,
    0xF5, 0xAD, 0xED, 0xB3, 0x34, 0x81, 0xF9, 0x9A, 0xFF, 0x07};
const uint8_t spF[] PROGMEM = {
    0xAB, 0x1B, 0x61, 0x94, 0xDD, 0xD6, 0xDC, 0xF1, 0x74, 0xDD, 0x37, 0xB9,
    0xE7, 0xEA, 0xD3, 0x35, 0xB3, 0x1C, 0xE1, 0xAF, 0x6F, 0x77, 0xC7, 0xB5,
    0xD4, 0xE0, 0x56, 0x9C, 0x77, 0xDB, 0x5A, 0x9D, 0xEB, 0x98, 0x8C, 0x61,
    0xC0, 0x30, 0xE9, 0x1A, 0xB0, 0x80, 0x05, 0x14, 0x30, 0x6D, 0xBB, 0x06,
    0x24, 0x20, 0x01, 0x0E, 0x10, 0xA0, 0x06, 0xB5, 0xFF, 0x07};
const uint8_t spG[] PROGMEM = {
    0x6E, 0x3F, 0x29, 0x8D, 0x98, 0x95, 0xCD, 0x3D, 0x00, 0xAB, 0x38,
    0x95, 0xE2, 0xD4, 0xEB, 0x34, 0x81, 0x7A, 0xF2, 0x51, 0x53, 0x50,
    0x75, 0xEB, 0xCE, 0x76, 0xB6, 0xD3, 0x95, 0x8D, 0x92, 0x48, 0x99,
    0xAB, 0x77, 0xBE, 0xCB, 0xDD, 0x8E, 0x71, 0x96, 0x04, 0x8C, 0x5A,
    0x3C, 0xE7, 0x39, 0xF7, 0xAD, 0x6E, 0xF5, 0x2A, 0xD7, 0x2A, 0x85,
    0xE0, 0xB9, 0x26, 0x3E, 0xF1, 0xF9, 0x7F};
const uint8_t spH[] PROGMEM = {
    0x65, 0x18, 0x6D, 0x90, 0x2D, 0xD6, 0xEC, 0xF6, 0x56, 0xB7, 0xBC, 0xC5,
    0xAE, 0xC7, 0x30, 0xA3, 0x01, 0x6D, 0x2D, 0xCE, 0x8B, 0x3D, 0xDC, 0xD6,
    0x3C, 0x61, 0x76, 0xC5, 0x25, 0x9B, 0x08, 0xE5, 0x2E, 0x22, 0x1B, 0x00,
    0x80, 0x01, 0x2B, 0x87, 0x38, 0x60, 0xE5, 0xED, 0x08, 0x58, 0xC0, 0x02,
    0x16, 0xB0, 0x80, 0x06, 0x34, 0x40, 0x80, 0x76, 0xD3, 0xFE, 0x1F};
const uint8_t spI[] PROGMEM = {
    0xAA, 0x8D, 0x63, 0xA8, 0xAA, 0x66, 0xAD, 0xB9, 0xA8, 0xCB, 0x08,
    0xDD, 0x7C, 0xFB, 0x5B, 0xDF, 0xFA, 0x36, 0xB7, 0x39, 0x6D, 0xB5,
    0xA3, 0x15, 0xBA, 0xF8, 0x76, 0xBB, 0xDF, 0xD3, 0x9E, 0xD7, 0xDA,
    0x5C, 0x49, 0xA5, 0x2D, 0xDE, 0x7B, 0xDB, 0x6B, 0x76, 0x29, 0xAF,
    0xC7, 0x6D, 0xEF, 0x31, 0xD8, 0x5C, 0x1E, 0xF7, 0xBD, 0x1E, 0xF5,
    0x48, 0xE7, 0x28, 0x89, 0xE2, 0xF2, 0x38, 0x5F, 0xF9, 0xFE, 0x7F};
const uint8_t spL[] PROGMEM = {
    0x6B, 0x68, 0x2E, 0xD8, 0x2A, 0x37, 0xDF, 0xFE, 0xF6, 0xA7, 0xAF,
    0x21, 0xBC, 0xC4, 0x17, 0xDF, 0xFE, 0xF6, 0x67, 0xC8, 0x6A, 0xC3,
    0x4D, 0x3A, 0xDF, 0x61, 0x4D, 0x95, 0x6C, 0xA6, 0x71, 0x9E, 0xB1,
    0x36, 0x98, 0x53, 0x49, 0x5E, 0xFB, 0x5A, 0x8E, 0x0A, 0x7A, 0x43,
    0xD9, 0x4F, 0x3C, 0xC2, 0x59, 0xE0, 0xF4, 0x08, 0xF9, 0x09, 0x67,
    0x03, 0x31, 0x19, 0xA2, 0x25, 0x9E, 0xFF, 0x0F};
const uint8_t spJ[] PROGMEM = {
    0x6E, 0x5A, 0xC1, 0x99, 0x54, 0xB2, 0x09, 0x60, 0x49, 0x22, 0x07, 0xEC,
    0xA8, 0x16, 0x80, 0x5D, 0x26, 0xC7, 0xD0, 0xA3, 0x92, 0x78, 0x74, 0x3E,
    0x55, 0x2F, 0x21, 0x6A, 0xB1, 0xFA, 0x56, 0xB7, 0xBA, 0xD5, 0xAD, 0x6F,
    0x7D, 0xBB, 0x3D, 0x8E, 0x75, 0xB4, 0x22, 0x36, 0x7F, 0x53, 0xCF, 0x7E,
    0xB5, 0x67, 0x96, 0x61, 0x34, 0xDB, 0x52, 0x9F, 0xF4, 0x8E, 0xDC, 0x88,
    0xE1, 0x5F, 0xF2, 0x9D, 0xEF, 0xFF, 0x07};
const uint8_t spK[] PROGMEM = {
    0x01, 0x18, 0x91, 0xB9, 0x00, 0x4D, 0x91, 0x46, 0x60, 0x65, 0x2D,
    0xB3, 0xB8, 0x67, 0xED, 0x53, 0xF4, 0x14, 0x64, 0x11, 0x4B, 0x6E,
    0x79, 0x8B, 0x5B, 0xDE, 0xF2, 0x74, 0xC3, 0x05, 0x6A, 0xE7, 0xEA,
    0x3D, 0xEC, 0x71, 0x2F, 0x6D, 0x1F, 0xB1, 0x00, 0x2B, 0xDF, 0xF4,
    0xA3, 0x1D, 0xB3, 0x24, 0x60, 0xD4, 0xE2, 0x7A, 0xE5, 0x2B, 0xDF,
    0xE9, 0x1E, 0x43, 0x48, 0xA3, 0xEB, 0xE4, 0xFB, 0xFF, 0x01};
const uint8_t spM[] PROGMEM = {
    0xA9, 0xE8, 0xC5, 0xD8, 0x73, 0x16, 0xCF, 0xE2, 0x0E, 0xB7, 0xBB,
    0xCD, 0xA9, 0xBB, 0x6F, 0xF1, 0xF0, 0xD5, 0xB7, 0xBE, 0xCD, 0xEE,
    0xC6, 0x50, 0x63, 0x72, 0x98, 0x58, 0xEE, 0x73, 0x5F, 0xDB, 0xD6,
    0x62, 0x72, 0x98, 0x58, 0xAE, 0x7B, 0xDD, 0xD3, 0x5E, 0x45, 0x72,
    0x93, 0xD8, 0x8D, 0x87, 0x3D, 0xEC, 0x61, 0xCF, 0x70, 0x96, 0x58,
    0xE1, 0xA2, 0x4D, 0xE2, 0x15, 0xEF, 0xFF, 0x07};
const uint8_t spN[] PROGMEM = {
    0x41, 0xEE, 0xD1, 0xC8, 0xB3, 0x16, 0xEF, 0xEE, 0xD4, 0xC3, 0x35,
    0x59, 0xC4, 0xE3, 0x5B, 0xDD, 0xEA, 0x56, 0xBB, 0x59, 0xED, 0x92,
    0xCD, 0x91, 0xB4, 0x78, 0x4F, 0x63, 0x19, 0x9E, 0x38, 0x2C, 0x9C,
    0xCE, 0xA5, 0xAF, 0xF5, 0x08, 0xC7, 0xB0, 0xC2, 0x61, 0x1E, 0x35,
    0x1E, 0xF1, 0x8C, 0x57, 0xBC, 0xD3, 0xDD, 0x4D, 0x49, 0xB8, 0xCE,
    0x0E, 0xF7, 0x34, 0xAD, 0x16, 0xBC, 0xF9, 0xFF, 0x01};
const uint8_t spO[] PROGMEM = {
    0xA3, 0x6D, 0xB4, 0xBA, 0x8D, 0xBC, 0xAD, 0xA6, 0x92, 0xEC, 0x0E, 0xF2,
    0xB6, 0xAB, 0x5D, 0x8C, 0xA2, 0xE0, 0xEE, 0x16, 0xF6, 0x3F, 0xCB, 0x39,
    0xCC, 0xB1, 0xAC, 0x91, 0xE5, 0x0C, 0x8B, 0xBF, 0xB0, 0x3B, 0xD3, 0x1D,
    0x28, 0x59, 0xE2, 0xE9, 0x4F, 0x7B, 0xF9, 0xE7, 0xFF, 0x01};
const uint8_t spP[] PROGMEM = {
    0x02, 0x88, 0x26, 0xD4, 0x00, 0x6D, 0x96, 0xB5, 0xB8, 0x25, 0x05,
    0x89, 0x6C, 0x3D, 0xD2, 0xE6, 0x51, 0xB3, 0xA6, 0xF4, 0x48, 0x67,
    0x09, 0xA0, 0x8C, 0xC7, 0x33, 0x9B, 0x79, 0xCB, 0x67, 0x0E, 0x80,
    0xCA, 0xD7, 0xBD, 0x6A, 0xD5, 0x72, 0x06, 0xB4, 0xB5, 0xBA, 0xB7,
    0xBD, 0xAF, 0x73, 0x5D, 0xF3, 0x91, 0x8F, 0x78, 0xFE, 0x3F};
const uint8_t spQ[] PROGMEM = {
    0x0E, 0x98, 0xD5, 0x28, 0x02, 0x11, 0x18, 0xE9, 0xCC, 0x46, 0x98,
    0xF1, 0x66, 0xA7, 0x27, 0x1D, 0x21, 0x99, 0x92, 0xB6, 0xDC, 0x7C,
    0x17, 0xAB, 0x2C, 0xD2, 0x2D, 0x13, 0x3B, 0xEF, 0xAA, 0x75, 0xCE,
    0x94, 0x47, 0xD0, 0xEE, 0x3A, 0xC4, 0x29, 0x2F, 0x61, 0x35, 0x31,
    0xA2, 0x50, 0xB6, 0xF8, 0xCD, 0x1F, 0xFF, 0x0F};
const uint8_t spR[] PROGMEM = {
    0xAB, 0xC8, 0x72, 0x33, 0x93, 0xBB, 0xDC, 0xEE, 0xB6, 0xB7, 0xB9,
    0xF5, 0x68, 0x53, 0x5C, 0xA9, 0xA6, 0x4D, 0xB3, 0x6B, 0x73, 0x0A,
    0xCB, 0x71, 0xD8, 0xBB, 0xAF, 0x7D, 0x2F, 0x47, 0xB6, 0xC7, 0xF4,
    0x94, 0x37, 0x9D, 0xA9, 0x34, 0xF8, 0x53, 0x97, 0x78, 0xFD, 0x3F};
const uint8_t spS[] PROGMEM = {
    0x6B, 0x6E, 0xD9, 0x34, 0x6C, 0xE6, 0xDC, 0xF6, 0x36, 0xB7, 0xBE, 0xF5,
    0x19, 0xAA, 0x0F, 0x2D, 0xDA, 0x25, 0x7B, 0x19, 0x5B, 0x4D, 0x9A, 0xA2,
    0xE7, 0xB8, 0x1D, 0x23, 0xA5, 0x26, 0x71, 0x2A, 0x03, 0xFC, 0x94, 0xE6,
    0x01, 0x0F, 0x68, 0x40, 0x03, 0x12, 0xE0, 0x00, 0x07, 0x30, 0xF0, 0xFF};
const uint8_t spT[] PROGMEM = {
    0x01, 0xD8, 0xB6, 0xDD, 0x01, 0x2F, 0xF4, 0x38, 0x60, 0xD5, 0xD1, 0x91,
    0x4D, 0x97, 0x84, 0xE6, 0x4B, 0x4E, 0x36, 0xB2, 0x10, 0x67, 0xCD, 0x19,
    0xD9, 0x2C, 0x01, 0x94, 0xF1, 0x78, 0x66, 0x33, 0xEB, 0x79, 0xAF, 0x7B,
    0x57, 0x87, 0x36, 0xAF, 0x52, 0x08, 0x9E, 0x6B, 0xEA, 0x5A, 0xB7, 0x7A,
    0x94, 0x73, 0x45, 0x47, 0xAC, 0x5A, 0x9C, 0xAF, 0xFF, 0x07};
const uint8_t spU[] PROGMEM = {
    0xA1, 0x9F, 0x9C, 0x94, 0x72, 0x26, 0x8D, 0x76, 0x07, 0x55, 0x90,
    0x78, 0x3C, 0xEB, 0x59, 0x9D, 0xA2, 0x87, 0x60, 0x76, 0xDA, 0x72,
    0x8B, 0x53, 0x36, 0xA5, 0x64, 0x2D, 0x7B, 0x6E, 0xB5, 0xFA, 0x24,
    0xDC, 0x32, 0xB1, 0x73, 0x1F, 0xFA, 0x1C, 0x16, 0xAB, 0xC6, 0xCA,
    0xE0, 0xB5, 0xDF, 0xCD, 0xA1, 0xD4, 0x78, 0x1B, 0xB6, 0x53, 0x97,
    0x74, 0xA7, 0x21, 0xBC, 0xE4, 0xFF, 0x01};
const uint8_t spV[] PROGMEM = {
    0x66, 0xF3, 0xD2, 0x38, 0x43, 0xB3, 0xD8, 0x2D, 0xAC, 0x4D, 0xBB, 0x70,
    0xB0, 0xDB, 0xB0, 0x0E, 0x17, 0x2C, 0x26, 0xAE, 0xD3, 0x32, 0x6C, 0xBB,
    0x32, 0xAB, 0x19, 0x63, 0xF7, 0x21, 0x6C, 0x9C, 0xE5, 0xD4, 0x33, 0xB6,
    0x80, 0xCB, 0x9A, 0x9B, 0xAF, 0x6C, 0xE5, 0x42, 0x70, 0x7F, 0xB3, 0xB3,
    0x9D, 0xEE, 0x7C, 0x55, 0x2B, 0x26, 0x40, 0xD5, 0xE2, 0xD9, 0xF6, 0xB1,
    0x4F, 0x75, 0xAB, 0x7B, 0x3D, 0xCA, 0x35, 0x4B, 0x13, 0x98, 0xAF, 0xA9,
    0x57, 0x7E, 0xF3, 0x97, 0xBE, 0x19, 0x0B, 0x31, 0xF3, 0xCD, 0xFF, 0x03};
const uint8_t spW[] PROGMEM = {
    0xA1, 0xDE, 0xC2, 0x44, 0xC2, 0xFC, 0x9C, 0x6A, 0x88, 0x70, 0x09, 0x59,
    0x7B, 0x8A, 0xCA, 0x3B, 0x3D, 0xA4, 0xCF, 0xCD, 0x56, 0x96, 0xC4, 0xA6,
    0xBB, 0xF4, 0x6E, 0x59, 0xE2, 0x9D, 0xEA, 0xE2, 0x4A, 0xD5, 0x12, 0x65,
    0xBB, 0xB3, 0xEB, 0x51, 0x57, 0x12, 0x99, 0xC1, 0xD9, 0x6E, 0xB7, 0xC7,
    0x31, 0x35, 0x92, 0x6A, 0xC9, 0x9B, 0xC7, 0x34, 0x4C, 0x12, 0x46, 0x6C,
    0x99, 0x73, 0x5F, 0xDA, 0xD2, 0x92, 0x92, 0x64, 0x6C, 0xEE, 0x6B, 0xD9,
    0x6A, 0x22, 0x71, 0x8F, 0xCF, 0xE5, 0x2C, 0x41, 0xD4, 0xDD, 0x36, 0xA5,
    0x3B, 0x19, 0xF5, 0x0C, 0xEE, 0x13, 0xEF, 0xFC, 0x9A, 0xD7, 0x85, 0xC8,
    0x62, 0xEE, 0x6D, 0xBF, 0xFF, 0x07};
const uint8_t spX[] PROGMEM = {
    0xAD, 0x68, 0xC9, 0xC5, 0x32, 0x56, 0xDF, 0xFA, 0x54, 0x2D, 0x35, 0x7B,
    0xF8, 0xEA, 0x5B, 0xDD, 0xE6, 0x4C, 0x6D, 0x04, 0xA6, 0xC5, 0xEA, 0xB9,
    0x84, 0xB5, 0x75, 0x23, 0x37, 0x4F, 0x83, 0x40, 0x11, 0xCA, 0x5D, 0x44,
    0x36, 0x00, 0x28, 0xA0, 0xE6, 0x31, 0x0F, 0x68, 0xC0, 0x00, 0xBF, 0x8D,
    0x79, 0xC0, 0x03, 0x16, 0xD0, 0x00, 0x07, 0xFE, 0x1F};
const uint8_t spY[] PROGMEM = {
    0x6A, 0xB1, 0xA2, 0xA7, 0x95, 0xD2, 0xD8, 0x25, 0x0F, 0xA3, 0x2D,
    0xB2, 0x7A, 0x1C, 0xB3, 0xDE, 0xE6, 0xD4, 0x45, 0x6D, 0x56, 0xCA,
    0x9A, 0x5B, 0xDF, 0xFA, 0xB6, 0xBB, 0xDB, 0xFD, 0x1A, 0x8A, 0x6F,
    0x2B, 0xF3, 0x37, 0x7B, 0x19, 0x4B, 0xD3, 0x25, 0x39, 0xFA, 0xB9,
    0x6F, 0x6D, 0xEB, 0x31, 0xC4, 0x5C, 0x1E, 0xF7, 0xAD, 0x1F, 0xE5,
    0x1C, 0xA5, 0x48, 0x5C, 0x1E, 0xD7, 0x2B, 0x5F, 0xF9, 0xFA, 0x7F};
const uint8_t spZ[] PROGMEM = {
    0x6D, 0xFD, 0xC6, 0x5C, 0x95, 0xD5, 0xF5, 0xD5, 0x02, 0x7B, 0x5D, 0xFD,
    0x51, 0x2D, 0x2A, 0xE4, 0x77, 0x75, 0xA3, 0x3A, 0xB1, 0xFA, 0x9B, 0x5D,
    0xEF, 0x6A, 0x55, 0x33, 0x27, 0x60, 0xD4, 0xE2, 0xD9, 0xCC, 0x76, 0x4E,
    0x73, 0x9D, 0x7B, 0x3F, 0xFB, 0x59, 0xAE, 0x55, 0x0A, 0xC1, 0x73, 0x4D,
    0xBD, 0xEA, 0x9D, 0x9E, 0x15, 0x12, 0xA0, 0x6B, 0x75, 0x7E, 0xFE, 0x1F};
