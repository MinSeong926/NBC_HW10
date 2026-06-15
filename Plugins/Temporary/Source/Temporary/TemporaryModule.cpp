// TemporaryModule.cpp

#include "TemporaryModule.h"

void FTemporaryModule::StartupModule()
{
    UE_LOG(LogTemp, Warning, TEXT("Temporary 플러그인이 로드되었습니다."));
}

void FTemporaryModule::ShutdownModule()
{
    UE_LOG(LogTemp, Warning, TEXT("Temporary 플러그인이 언로드되었습니다."));
}

// 플러그인 모듈 등록
IMPLEMENT_MODULE(FTemporaryModule, Temporary)