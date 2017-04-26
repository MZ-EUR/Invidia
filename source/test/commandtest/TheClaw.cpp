#include <d3d9.h>
void dump_buffer()
{

	IDirect3DDevice9 *Device;
	D3DFORMAT format;
	IDirect3DSurface9* pRenderTarget = NULL;
	IDirect3DSurface9* pDestTarget = NULL;
	const char file[] = "Pickture.bmp";
	// sanity checks.
	if (Device == NULL)
		return;
	// get the render target surface.
	HRESULT hr = Device->GetRenderTarget(0, &pRenderTarget);
	// get the current adapter display mode.
	//hr = pDirect3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT,&d3ddisplaymode);

	// create a destination surface.
	hr = Device->CreateOffscreenPlainSurface(50,
		50,
		format,
		D3DPOOL_SYSTEMMEM,
		&pDestTarget,
		NULL);
	//copy the render target to the destination surface.
	hr = Device->GetRenderTargetData(pRenderTarget, pDestTarget);
	//save its contents to a bitmap file.
	// clean up.
	pRenderTarget->Release();
	pDestTarget->Release();
}