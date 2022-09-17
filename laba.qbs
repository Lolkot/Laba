import qbs

QtApplication {
    cpp.cxxLanguageVersion: "c++11"

    consoleApplication: true
    files: [
        "main.cpp",
        "empty.h",
        "exception.h"
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
