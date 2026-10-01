# 문제 2 — 인지·제어 노드 연결 (ROS 2 Lyrical)

```
target_detector ──/target (PointStamped, best-effort depth 1)──▶ tracking_controller ──/pan/cmd_vel (Twist, 20 Hz)──▶ motor_driver (출력 OFF)
      └─/perception_status                                         ├─/tracking_status (20 Hz)
                                                                   └─/search (Search.action 서버)
```

| 경로 | 내용 |
|---|---|
| `ws/src/tracking_interfaces/action/Search.action` | /search 요청·결과·진행 |
| `ws/src/target_tracking/target_tracking/interface.py` | 토픽·타입·QoS·상태 값 **단일 정의**(노드·보고서·검사 공용) |
| `ws/src/target_tracking/config/tracking.yaml` | 게인·부호·데드밴드·주기·타임아웃·출력 OFF |
| `detector_node.py` | 문제 1 검출 → /target. 새 영상만 발행, 카메라 정지 시 발행 중단 |
| `controller_node.py` | 신선도 판정·상태·명령, /search 서버 |
| `motor_driver_node.py` | 유일한 하드웨어 출력 지점, 기본 OFF, 명령 끊김 감시 |
| `input_test` / `pan_sim` / `search_test` / `interface_check` | 시험 도구 |
| `make_report.py` | `results/`로 `results/REPORT.md` 생성 |

## 빌드
```bash
cd ~/Downloads/project_vision/problem2/ws
source /opt/ros/lyrical/setup.bash
colcon build --symlink-install
source install/setup.bash
```

## 시험 (모두 모터 출력 OFF)
```bash
ros2 launch target_tracking test_inputs.launch.py                # 다섯 입력 + 정지 영상·오래된 시각
ros2 launch target_tracking sign_demo.launch.py cmd_sign:=-1.0   # 부호 정상
ros2 launch target_tracking sign_demo.launch.py cmd_sign:=1.0    # 부호 반대
ros2 launch target_tracking search_test.launch.py                # /search 성공·실패·취소
ros2 launch target_tracking e2e_check.launch.py                  # 인지→제어→구동 + 인터페이스·QoS 검사(합성 영상)
python3 ../make_report.py
```

실제 카메라로 전체 연결:
```bash
ros2 launch target_tracking e2e_check.launch.py source:=realsense \
  config:=$HOME/Downloads/project_vision/problem1/config.yaml duration:=10.0 tag:=e2e_realsense
ros2 launch target_tracking bringup.launch.py                    # 상시 실행
```
카메라는 한 프로세스만 열 수 있다. 문제 1의 `run.py`가 실행 중이면 먼저 종료한다.
