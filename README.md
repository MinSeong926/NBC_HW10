# NBC_HW10 - 언리얼 모듈과 플러그인


# 필수 기능
1. **새 프로젝트 만들기**
    - [ ]  Third Person 샘플 프로젝트 생성
        - 샘플 프로젝트?
            
            !Games, Third Person, C++, Scalable. 프로젝트 이름은 “ModuleAndPlugin”
            
            Games, Third Person, C++, Scalable. 프로젝트 이름은 “ModuleAndPlugin”
            
        - 블루프린트 프로젝트 VS C++ 프로젝트
            - 블루프린트 프로젝트 : C++ 코드를 작성하지 않는 프로젝트.
            - C++ 프로젝트 → 개발자가 직접 모듈을 추가하고 임포트 할 수 있음.
                
                !image.png
                
2. **새 모듈(Test) 생성 및 설정**
    - [ ]  **모듈 폴더 구조 생성:** `Source/Test` 폴더를 만들고 필수 파일(`Test.Build.cs`, `Test.h`, `Test.cpp`)을 생성합니다.
    - [ ]  **Build.cs 정의:** `Core`, `Engine` 등 필수 종속성 모듈을 `PublicDependencyModuleNames`에 추가합니다.
    - [ ]  **모듈 매크로 구현:** `Test.cpp`에 일반 모듈을 위한 `IMPLEMENT_MODULE(FDefaultModuleImpl, Test);`를 선언합니다.
    
    > **💡 핵심 요약**
    > 
    > - **Public Dependency:** 헤더(.h)와 소스(.cpp) 모두에서 사용하는 모듈
    > - **Private Dependency:** 소스(.cpp) 파일에서만 사용하는 모듈

---

3. **모듈 연결 및 빌드 대상 등록 :** 생성한 모듈이 실제 컴파일 프로세스에 포함되도록 하기!
    - [ ]  **Target.cs 수정:** `ModuleAndPlugin.Target.cs`와 `Editor.Target.cs`의 `ExtraModuleNames`에 `"Test"`를 추가합니다.
    - [ ]  **.uproject 갱신:** 프로젝트 파일의 `Modules` 리스트에 `Test` 모듈을 추가하고, `LoadingPhase`를 `PreDefault`로 설정합니다.
    - [ ]  **프로젝트 재생성:** `.uproject` 우클릭을 통해 `Generate Visual Studio project files`를 실행하여 솔루션을 갱신합니다.

---

4. **모듈 간 상호작용 구현**
    - [ ]  **TestActor 생성:** `Test` 모듈에 속한 C++ 클래스(Actor 부모)를 생성하고 `BeginPlay`에서 로그를 출력하게 합니다.
    - [ ]  **Primary 모듈에서 참조:** 주 게임 모듈의 캐릭터 클래스에서 `TestActor.h`를 include하고 `SpawnActor` 로직을 작성합니다.
        - 새로 만든 모듈이 정상 작동하는지 화면에 메시지를 띄워 확인합니다.

---

5. **독립 플러그인(Temporary) 구축**
    - [ ]  **플러그인 기본 폴더 생성:** `Plugins/Temporary` 경로에 `Content`, `Source`, `Temporary.uplugin` 파일을 구성합니다.
    - [ ]  **.uplugin 작성:** 플러그인의 메타데이터와 포함될 모듈 정보를 JSON 형식으로 정확히 기입 합니다.
    - [ ]  **플러그인 모듈 설정:** 플러그인 내부의 `Source/Temporary` 폴더에 `Build.cs`와 모듈 인터페이스(`StartupModule`, `ShutdownModule`)를 구현합니다.
        - 재사용이 가능한 '플러그인' 구조를 수동으로 만들어 봅니다.

---

6. **플러그인 최종 연결 및 검증**
    - [ ]  **프로젝트 활성화:** `.uproject` 파일의 `Plugins` 항목에 `Temporary` 플러그인을 `Enabled: true`로 등록합니다.
    - [ ]  **에디터 확인:** 빌드 후 에디터의 '콘텐츠 브라우저'에서 플러그인 폴더와 내부 C++ 클래스가 보이는지 확인합니다.

---
# 도전 기능
- [ ]  새로운 모듈이나 새로운 플러그인 속에 클래스를 만들어보세요.
    - [ ]  UObject 자료형의 자식 클래스를 만듭니다.
    - [ ]  해당 클래스를 마치 캐릭터 클래스의 데이터 저장용 클래스로 사용해보세요.
