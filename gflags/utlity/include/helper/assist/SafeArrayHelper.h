#pragma once

class CSafeArrayHelper
{
public:
	CSafeArrayHelper();
	~CSafeArrayHelper();

public:
	bool		Create(VARTYPE  vt, UINT  cDims, UINT lBound, UINT cCount);
	bool		Destroy();
	UINT		GetDimension();

	bool		Attach(LPSAFEARRAY psa);
	bool		AttachFromVariant(VARIANT* pVariant);
	LPSAFEARRAY Detach();
	LPSAFEARRAY GetArray();
	bool		AccessData(void FAR* FAR* pvData);
	bool		UnaccessData();
	bool		Lock();
	bool		Unlock();
	bool		PutElement(long lIndices, void FAR* vData);
	bool		GetElement(long lIndices, void FAR* vData);
	VARIANT		GetAsVariant();

protected:
	LPSAFEARRAY	m_pSA;
};
