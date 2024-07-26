@echo off

pushd %~dp0\FidelityFX-SDK\sdk\

echo Building FFX_API_BACKEND DX12_X64...
start /WAIT /B %COMSPEC% "/C BuildFidelityFXSDK.bat -DFFX_API_BACKEND=DX12_X64 -DFFX_FI=ON -DFFX_OF=ON -DFFX_AUTO_COMPILE_SHADERS=1"

echo Building FFX_API_BACKEND VK_X64...
start /WAIT /B %COMSPEC% "/C BuildFidelityFXSDK.bat -DFFX_API_BACKEND=VK_X64 -DFFX_FI=ON -DFFX_OF=ON -DFFX_AUTO_COMPILE_SHADERS=1"

popd