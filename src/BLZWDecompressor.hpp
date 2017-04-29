/* Copyright (C) Teemu Suutari */

#ifndef BLZWDECOMPRESSOR_HPP
#define BLZWDECOMPRESSOR_HPP

#include "XPKDecompressor.hpp"

class BLZWDecompressor : public XPKDecompressor
{
public:
	BLZWDecompressor(uint32_t hdr,const Buffer &packedData,std::unique_ptr<XPKDecompressor::State> &state);

	virtual ~BLZWDecompressor();

	virtual bool isValid() const override final;
	virtual bool verifyPacked() const override final;
	virtual bool verifyRaw(const Buffer &rawData) const override final;

	virtual const std::string &getSubName() const override final;

	virtual bool decompress(Buffer &rawData,const Buffer &previousData) override final;

	static bool detectHeaderXPK(uint32_t hdr);
	static bool isRecursive();
	static std::unique_ptr<XPKDecompressor> create(uint32_t hdr,const Buffer &packedData,std::unique_ptr<XPKDecompressor::State> &state);

private:
	const Buffer &_packedData;

	bool		_isValid=false;
	uint32_t	_maxBits=0;
	size_t		_stackLength=0;
};

#endif
