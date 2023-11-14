#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/yin-roc/1_Code/Ubuntu20.04/ROS_demo/demo03_ws/src/arbotix_ros/arbotix_python"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/yin-roc/1_Code/Ubuntu20.04/ROS_demo/demo03_ws/install/lib/python3/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/yin-roc/1_Code/Ubuntu20.04/ROS_demo/demo03_ws/install/lib/python3/dist-packages:/home/yin-roc/1_Code/Ubuntu20.04/ROS_demo/demo03_ws/build/lib/python3/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/yin-roc/1_Code/Ubuntu20.04/ROS_demo/demo03_ws/build" \
    "/usr/bin/python3" \
    "/home/yin-roc/1_Code/Ubuntu20.04/ROS_demo/demo03_ws/src/arbotix_ros/arbotix_python/setup.py" \
    egg_info --egg-base /home/yin-roc/1_Code/Ubuntu20.04/ROS_demo/demo03_ws/build/arbotix_ros/arbotix_python \
    build --build-base "/home/yin-roc/1_Code/Ubuntu20.04/ROS_demo/demo03_ws/build/arbotix_ros/arbotix_python" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/yin-roc/1_Code/Ubuntu20.04/ROS_demo/demo03_ws/install" --install-scripts="/home/yin-roc/1_Code/Ubuntu20.04/ROS_demo/demo03_ws/install/bin"