#Déclaration du projet
project(camera_test)

#link_directories(/usr/local/lib)

set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/)

find_package(CUDA REQUIRED) 
#set(OpenCV_DIR "/usr/local/lib/OpenCV/")
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} ".")

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)



list(APPEND HEADER_REP ${ROOT_DIR}/ ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES} "/usr/local/cuda/samples/common/inc/" "${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES}/../samples/common/inc")


set(CPP_FILES )
set(CU_FILES ${ROOT_DIR}/main_nano.cu ${ROOT_DIR}/mylib.cu)


set(CUDA_SEPARABLE_COMPILATION ON)
set(CUDA_NVCC_FLAGS "-lineinfo;-I\"${ROOT_DIR}/inc\" -I\"${ROOT_DIR}/\" -I\"/usr/local/cuda/samples/common/inc/\"")


cuda_add_executable(camera_test ${CPP_FILES} ${CU_FILES} ${HEADER_FILES})

set_target_properties(camera_test PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(camera_test PUBLIC ${ROOT_DIR}/inc/ /usr/local/cuda/samples/common/inc/)
target_link_libraries(camera_test Qt5::Widgets)
target_link_libraries(camera_test Qt5::Core)
target_link_libraries(camera_test opencv_core opencv_highgui opencv_imgproc opencv_imgcodecs opencv_video opencv_videoio)
