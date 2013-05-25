/*                    The Quest Operating System
 *  Copyright (C) 2005-2012  Richard West, Boston University
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "usb.h"
#include <qcv/qcv.h>

#define CAM_BUF_SIZE (4096*10)
char camera_buffer[CAM_BUF_SIZE];

void main()
{
  char* video_memory;
  qcv_capture_t camera_capture;
  int camera_fd;
  qcv_frame_t frame;
  
  if(qcv_capture_from_camera(&camera_capture, 0) < 0) {
    printf("Failed to initialise camera capture \n");
    exit(EXIT_FAILURE);
  }

  printf("About to enable video mode\n");
  if(enable_video(1, &video_memory) < 0) {
    printf("Failed to enable video mode\n");
    exit(EXIT_FAILURE);
  }

  while(1) {
    if(qcv_query_frame(&camera_capture, &frame) < 0) {
      printf("Failed to pull frame\n");
      exit(EXIT_FAILURE);
    }
    
    qcv_display_frame(&frame, video_memory);
    qcv_release_frame(&frame);
  }

  printf("At end of camera\n");
  while(1);
  
}


/* 
 * Local Variables:
 * indent-tabs-mode: nil
 * mode: C
 * c-file-style: "gnu"
 * c-basic-offset: 2
 * End: 
 */

/* vi: set et sw=2 sts=2: */
