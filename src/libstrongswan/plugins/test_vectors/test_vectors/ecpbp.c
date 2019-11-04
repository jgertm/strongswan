/*
 * Copyright (C) 2015 Martin Willi
 * Copyright (C) 2015 revosec AG
 *
 * Copyright (C) 2019 Andreas Steffen
 * HSR Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the Licenseor (at your
 * option) any later version. See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be usefulbut
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 */

#include <crypto/crypto_tester.h>

/**
 * Test vectors from RFC6923/RFC7027
 */

ke_test_vector_t ecp224bp = {
	.method = ECP_224_BP,
	.seed = chunk_from_chars(
		0x7c, 0x4b, 0x7a, 0x2c, 0x8a, 0x4b, 0xad, 0x1f, 0xbb, 0x7d,
		0x79, 0xcc, 0x09, 0x55, 0xdb, 0x7c, 0x6a, 0x46, 0x60, 0xca,
		0x64, 0xcc, 0x47, 0x78, 0x15, 0x9b, 0x49, 0x5e, /* - */
		0x63, 0x97, 0x6d, 0x4a, 0xae, 0x6c, 0xd0, 0xf6, 0xdd, 0x18,
		0xde, 0xfe, 0xf5, 0x5d, 0x96, 0x56, 0x9d, 0x05, 0x07, 0xc0,
		0x3e, 0x74, 0xd6, 0x48, 0x6f, 0xfa, 0x28, 0xfb),
	.pub_i = chunk_from_chars(
		0xb1, 0x04, 0xa6, 0x7a, 0x6f, 0x6e, 0x85, 0xe1, 0x4e, 0xc1,
		0x82, 0x5e, 0x15, 0x39, 0xe8, 0xec, 0xdb, 0xbf, 0x58, 0x49,
		0x22, 0x36, 0x7d, 0xd8, 0x8c, 0x6b, 0xdc, 0xf2, 0x46, 0xd7,
		0x82, 0xe7, 0xfd, 0xb5, 0xf6, 0x0c, 0xd8, 0x40, 0x43, 0x01,
		0xac, 0x59, 0x49, 0xc5, 0x8e, 0xdb, 0x26, 0xbc, 0x68, 0xba,
		0x07, 0x69, 0x5b, 0x75, 0x0a, 0x94),
	.pub_r = chunk_from_chars(
		0x2a, 0x97, 0x08, 0x9a, 0x92, 0x96, 0x14, 0x7b, 0x71, 0xb2,
		0x1a, 0x4b, 0x57, 0x4e, 0x12, 0x78, 0x24, 0x5b, 0x53, 0x6f,
		0x14, 0xd8, 0xc2, 0xb9, 0xd0, 0x7a, 0x87, 0x4e, 0x9b, 0x90,
		0x0d, 0x7c, 0x77, 0xa7, 0x09, 0xa7, 0x97, 0x27, 0x6b, 0x8c,
		0xa1, 0xba, 0x61, 0xbb, 0x95, 0xb5, 0x46, 0xfc, 0x29, 0xf8,
		0x62, 0xe4, 0x4d, 0x59, 0xd2, 0x5b),
	.shared = chunk_from_chars(
		0x31, 0x2d, 0xfd, 0x98, 0x78, 0x3f, 0x9f, 0xb7, 0x7b, 0x97,
		0x04, 0x94, 0x5a, 0x73, 0xbe, 0xb6, 0xdc, 0xcb, 0xe3, 0xb6,
		0x5d, 0x0f, 0x96, 0x7d, 0xca, 0xb5, 0x74, 0xeb)
};

ke_test_vector_t ecp256bp = {
	.method = ECP_256_BP,
	.seed = chunk_from_chars(
		0x81, 0xdb, 0x1e, 0xe1, 0x00, 0x15, 0x0f, 0xf2, 0xea, 0x33,
		0x8d, 0x70, 0x82, 0x71, 0xbe, 0x38, 0x30, 0x0c, 0xb5, 0x42,
		0x41, 0xd7, 0x99, 0x50, 0xf7, 0x7b, 0x06, 0x30, 0x39, 0x80,
		0x4f, 0x1d, /* - */
		0x55, 0xe4, 0x0b, 0xc4, 0x1e, 0x37, 0xe3, 0xe2, 0xad, 0x25,
		0xc3, 0xc6, 0x65, 0x45, 0x11, 0xff, 0xa8, 0x47, 0x4a, 0x91,
		0xa0, 0x03, 0x20, 0x87, 0x59, 0x38, 0x52, 0xd3, 0xe7, 0xd7,
		0x6b, 0xd3),
	.pub_i = chunk_from_chars(
		0x44, 0x10, 0x6e, 0x91, 0x3f, 0x92, 0xbc, 0x02, 0xa1, 0x70,
		0x5d, 0x99, 0x53, 0xa8, 0x41, 0x4d, 0xb9, 0x5e, 0x1a, 0xaa,
		0x49, 0xe8, 0x1d, 0x9e, 0x85, 0xf9, 0x29, 0xa8, 0xe3, 0x10,
		0x0b, 0xe5, 0x8a, 0xb4, 0x84, 0x6f, 0x11, 0xca, 0xcc, 0xb7,
		0x3c, 0xe4, 0x9c, 0xbd, 0xd1, 0x20, 0xf5, 0xa9, 0x00, 0xa6,
		0x9f, 0xd3, 0x2c, 0x27, 0x22, 0x23, 0xf7, 0x89, 0xef, 0x10,
		0xeb, 0x08, 0x9b, 0xdc),
	.pub_r = chunk_from_chars(
		0x8d, 0x2d, 0x68, 0x8c, 0x6c, 0xf9, 0x3e, 0x11, 0x60, 0xad,
		0x04, 0xcc, 0x44, 0x29, 0x11, 0x7d, 0xc2, 0xc4, 0x18, 0x25,
		0xe1, 0xe9, 0xfc, 0xa0, 0xad, 0xdd, 0x34, 0xe6, 0xf1, 0xb3,
		0x9f, 0x7b, 0x99, 0x0c, 0x57, 0x52, 0x08, 0x12, 0xbe, 0x51,
		0x26, 0x41, 0xe4, 0x70, 0x34, 0x83, 0x21, 0x06, 0xbc, 0x7d,
		0x3e, 0x8d, 0xd0, 0xe4, 0xc7, 0xf1, 0x13, 0x6d, 0x70, 0x06,
		0x54, 0x7c, 0xec, 0x6a),
	.shared = chunk_from_chars(
		0x89, 0xaf, 0xc3, 0x9d, 0x41, 0xd3, 0xb3, 0x27, 0x81, 0x4b,
		0x80, 0x94, 0x0b, 0x04, 0x25, 0x90, 0xf9, 0x65, 0x56, 0xec,
		0x91, 0xe6, 0xae, 0x79, 0x39, 0xbc, 0xe3, 0x1f, 0x3a, 0x18,
		0xbf, 0x2b)
};

ke_test_vector_t ecp384bp = {
	.method = ECP_384_BP,
	.seed = chunk_from_chars(
		0x1e, 0x20, 0xf5, 0xe0, 0x48, 0xa5, 0x88, 0x6f, 0x1f, 0x15,
		0x7c, 0x74, 0xe9, 0x1b, 0xde, 0x2b, 0x98, 0xc8, 0xb5, 0x2d,
		0x58, 0xe5, 0x00, 0x3d, 0x57, 0x05, 0x3f, 0xc4, 0xb0, 0xbd,
		0x65, 0xd6, 0xf1, 0x5e, 0xb5, 0xd1, 0xee, 0x16, 0x10, 0xdf,
		0x87, 0x07, 0x95, 0x14, 0x36, 0x27, 0xd0, 0x42, /* - */
		0x03, 0x26, 0x40, 0xbc, 0x60, 0x03, 0xc5, 0x92, 0x60, 0xf7,
		0x25, 0x0c, 0x3d, 0xb5, 0x8c, 0xe6, 0x47, 0xf9, 0x8e, 0x12,
		0x60, 0xac, 0xce, 0x4a, 0xcd, 0xa3, 0xdd, 0x86, 0x9f, 0x74,
		0xe0, 0x1f, 0x8b, 0xa5, 0xe0, 0x32, 0x43, 0x09, 0xdb, 0x6a,
		0x98, 0x31, 0x49, 0x7a, 0xba, 0xc9, 0x66, 0x70),
	.pub_i = chunk_from_chars(
		0x68, 0xb6, 0x65, 0xdd, 0x91, 0xc1, 0x95, 0x80, 0x06, 0x50,
		0xcd, 0xd3, 0x63, 0xc6, 0x25, 0xf4, 0xe7, 0x42, 0xe8, 0x13,
		0x46, 0x67, 0xb7, 0x67, 0xb1, 0xb4, 0x76, 0x79, 0x35, 0x88,
		0xf8, 0x85, 0xab, 0x69, 0x8c, 0x85, 0x2d, 0x4a, 0x6e, 0x77,
		0xa2, 0x52, 0xd6, 0x38, 0x0f, 0xca, 0xf0, 0x68, 0x55, 0xbc,
		0x91, 0xa3, 0x9c, 0x9e, 0xc0, 0x1d, 0xee, 0x36, 0x01, 0x7b,
		0x7d, 0x67, 0x3a, 0x93, 0x12, 0x36, 0xd2, 0xf1, 0xf5, 0xc8,
		0x39, 0x42, 0xd0, 0x49, 0xe3, 0xfa, 0x20, 0x60, 0x74, 0x93,
		0xe0, 0xd0, 0x38, 0xff, 0x2f, 0xd3, 0x0c, 0x2a, 0xb6, 0x7d,
		0x15, 0xc8, 0x5f, 0x7f, 0xaa, 0x59),
	.pub_r = chunk_from_chars(
		0x4d, 0x44, 0x32, 0x6f, 0x26, 0x9a, 0x59, 0x7a, 0x5b, 0x58,
		0xbb, 0xa5, 0x65, 0xda, 0x55, 0x56, 0xed, 0x7f, 0xd9, 0xa8,
		0xa9, 0xeb, 0x76, 0xc2, 0x5f, 0x46, 0xdb, 0x69, 0xd1, 0x9d,
		0xc8, 0xce, 0x6a, 0xd1, 0x8e, 0x40, 0x4b, 0x15, 0x73, 0x8b,
		0x20, 0x86, 0xdf, 0x37, 0xe7, 0x1d, 0x1e, 0xb4, 0x62, 0xd6,
		0x92, 0x13, 0x6d, 0xe5, 0x6c, 0xbe, 0x93, 0xbf, 0x5f, 0xa3,
		0x18, 0x8e, 0xf5, 0x8b, 0xc8, 0xa3, 0xa0, 0xec, 0x6c, 0x1e,
		0x15, 0x1a, 0x21, 0x03, 0x8a, 0x42, 0xe9, 0x18, 0x53, 0x29,
		0xb5, 0xb2, 0x75, 0x90, 0x3d, 0x19, 0x2f, 0x8d, 0x4e, 0x1f,
		0x32, 0xfe, 0x9c, 0xc7, 0x8c, 0x48),
	.shared = chunk_from_chars(
		0x0b, 0xd9, 0xd3, 0xa7, 0xea, 0x0b, 0x3d, 0x51, 0x9d, 0x09,
		0xd8, 0xe4, 0x8d, 0x07, 0x85, 0xfb, 0x74, 0x4a, 0x6b, 0x35,
		0x5e, 0x63, 0x04, 0xbc, 0x51, 0xc2, 0x29, 0xfb, 0xbc, 0xe2,
		0x39, 0xbb, 0xad, 0xf6, 0x40, 0x37, 0x15, 0xc3, 0x5d, 0x4f,
		0xb2, 0xa5, 0x44, 0x4f, 0x57, 0x5d, 0x4f, 0x42)
};

ke_test_vector_t ecp512bp = {
	.method = ECP_512_BP,
	.seed = chunk_from_chars(
		0x16, 0x30, 0x2f, 0xf0, 0xdb, 0xbb, 0x5a, 0x8d, 0x73, 0x3d,
		0xab, 0x71, 0x41, 0xc1, 0xb4, 0x5a, 0xcb, 0xc8, 0x71, 0x59,
		0x39, 0x67, 0x7f, 0x6a, 0x56, 0x85, 0x0a, 0x38, 0xbd, 0x87,
		0xbd, 0x59, 0xb0, 0x9e, 0x80, 0x27, 0x96, 0x09, 0xff, 0x33,
		0x3e, 0xb9, 0xd4, 0xc0, 0x61, 0x23, 0x1f, 0xb2, 0x6f, 0x92,
		0xee, 0xb0, 0x49, 0x82, 0xa5, 0xf1, 0xd1, 0x76, 0x4c, 0xad,
		0x57, 0x66, 0x54, 0x22, /* - */
		0x23, 0x0e, 0x18, 0xe1, 0xbc, 0xc8, 0x8a, 0x36, 0x2f, 0xa5,
		0x4e, 0x4e, 0xa3, 0x90, 0x20, 0x09, 0x29, 0x2f, 0x7f, 0x80,
		0x33, 0x62, 0x4f, 0xd4, 0x71, 0xb5, 0xd8, 0xac, 0xe4, 0x9d,
		0x12, 0xcf, 0xab, 0xbc, 0x19, 0x96, 0x3d, 0xab, 0x8e, 0x2f,
		0x1e, 0xba, 0x00, 0xbf, 0xfb, 0x29, 0xe4, 0xd7, 0x2d, 0x13,
		0xf2, 0x22, 0x45, 0x62, 0xf4, 0x05, 0xcb, 0x80, 0x50, 0x36,
		0x66, 0xb2, 0x54, 0x29),
	.pub_i = chunk_from_chars(
		0x0a, 0x42, 0x05, 0x17, 0xe4, 0x06, 0xaa, 0xc0, 0xac, 0xdc,
		0xe9, 0x0f, 0xcd, 0x71, 0x48, 0x77, 0x18, 0xd3, 0xb9, 0x53,
		0xef, 0xd7, 0xfb, 0xec, 0x5f, 0x7f, 0x27, 0xe2, 0x8c, 0x61,
		0x49, 0x99, 0x93, 0x97, 0xe9, 0x1e, 0x02, 0x9e, 0x06, 0x45,
		0x7d, 0xb2, 0xd3, 0xe6, 0x40, 0x66, 0x8b, 0x39, 0x2c, 0x2a,
		0x7e, 0x73, 0x7a, 0x7f, 0x0b, 0xf0, 0x44, 0x36, 0xd1, 0x16,
		0x40, 0xfd, 0x09, 0xfd, 0x72, 0xe6, 0x88, 0x2e, 0x8d, 0xb2,
		0x8a, 0xad, 0x36, 0x23, 0x7c, 0xd2, 0x5d, 0x58, 0x0d, 0xb2,
		0x37, 0x83, 0x96, 0x1c, 0x8d, 0xc5, 0x2d, 0xfa, 0x2e, 0xc1,
		0x38, 0xad, 0x47, 0x2a, 0x0f, 0xce, 0xf3, 0x88, 0x7c, 0xf6, /* 100 */
		0x2b, 0x62, 0x3b, 0x2a, 0x87, 0xde, 0x5c, 0x58, 0x83, 0x01,
		0xea, 0x3e, 0x5f, 0xc2, 0x69, 0xb3, 0x73, 0xb6, 0x07, 0x24,
		0xf5, 0xe8, 0x2a, 0x6a, 0xd1, 0x47, 0xfd, 0xe7),
	.pub_r = chunk_from_chars(
		0x9d, 0x45, 0xf6, 0x6d, 0xe5, 0xd6, 0x7e, 0x2e, 0x6d, 0xb6,
		0xe9, 0x3a, 0x59, 0xce, 0x0b, 0xb4, 0x81, 0x06, 0x09, 0x7f,
		0xf7, 0x8a, 0x08, 0x1d, 0xe7, 0x81, 0xcd, 0xb3, 0x1f, 0xce,
		0x8c, 0xcb, 0xaa, 0xea, 0x8d, 0xd4, 0x32, 0x0c, 0x41, 0x19,
		0xf1, 0xe9, 0xcd, 0x43, 0x7a, 0x2e, 0xab, 0x37, 0x31, 0xfa,
		0x96, 0x68, 0xab, 0x26, 0x8d, 0x87, 0x1d, 0xed, 0xa5, 0x5a,
		0x54, 0x73, 0x19, 0x9f, 0x2f, 0xdc, 0x31, 0x30, 0x95, 0xbc,
		0xdd, 0x5f, 0xb3, 0xa9, 0x16, 0x36, 0xf0, 0x7a, 0x95, 0x9c,
		0x8e, 0x86, 0xb5, 0x63, 0x6a, 0x1e, 0x93, 0x0e, 0x83, 0x96,
		0x04, 0x9c, 0xb4, 0x81, 0x96, 0x1d, 0x36, 0x5c, 0xc1, 0x14, /* 100 */
		0x53, 0xa0, 0x6c, 0x71, 0x98, 0x35, 0x47, 0x5b, 0x12, 0xcb,
		0x52, 0xfc, 0x3c, 0x38, 0x3b, 0xce, 0x35, 0xe2, 0x7e, 0xf1,
		0x94, 0x51, 0x2b, 0x71, 0x87, 0x62, 0x85, 0xfa),
	.shared = chunk_from_chars(
		0xa7, 0x92, 0x70, 0x98, 0x65, 0x5f, 0x1f, 0x99, 0x76, 0xfa,
		0x50, 0xa9, 0xd5, 0x66, 0x86, 0x5d, 0xc5, 0x30, 0x33, 0x18,
		0x46, 0x38, 0x1c, 0x87, 0x25, 0x6b, 0xaf, 0x32, 0x26, 0x24,
		0x4b, 0x76, 0xd3, 0x64, 0x03, 0xc0, 0x24, 0xd7, 0xbb, 0xf0,
		0xaa, 0x08, 0x03, 0xea, 0xff, 0x40, 0x5d, 0x3d, 0x24, 0xf1,
		0x1a, 0x9b, 0x5c, 0x0b, 0xef, 0x67, 0x9f, 0xe1, 0x45, 0x4b,
		0x21, 0xc4, 0xcd, 0x1f)
};
