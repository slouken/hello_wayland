#include <stdint.h>

#include "libavutil/rational.h"

#include "wayout.h"

struct vid_out_env_s;
typedef struct vid_out_env_s vid_out_env_t;

#define WOUT_FLAG_FULLSCREEN 1
#define WOUT_FLAG_NO_WAIT    2

struct AVFrame;
struct AVCodecContext;
struct AVDRMFrameDescriptor;

int vidout_wayland_get_buffer2(struct AVCodecContext *s, struct AVFrame *frame, int flags);
void vidout_wayland_modeset(struct vid_out_env_s * dpo, int w, int h, AVRational frame_rate);
int vidout_wayland_display(struct vid_out_env_s * dpo, struct AVFrame * frame);
const struct AVDRMFrameDescriptor *get_frame_drm_descriptor(struct AVFrame *const frame);
void add_frame_fence(vid_out_env_t * const ve, struct AVFrame *const frame);
struct vid_out_env_s * vidout_wayland_new(unsigned int flags);
struct vid_out_env_s * dmabuf_wayland_out_new(unsigned int flags);
struct vid_out_env_s * vidout_simple_new();
struct vid_out_env_s * vidout_wayland_new_from(struct wl_display *display, struct wl_surface *surface, struct wp_viewport *viewport, const wo_rect_t size);
wo_window_t *vidout_wayland_get_window(vid_out_env_t * const ve);
void vidout_wayland_delete(struct vid_out_env_s * dpo);

void vidout_wayland_runticker(struct vid_out_env_s * dpo, const char * text);
void vidout_wayland_runcube(struct vid_out_env_s * dpo);

