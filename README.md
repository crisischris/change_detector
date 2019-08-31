# change_detector
Change Detector is a command line application written in c++ using openCV library and Xcode.  Program is primarily for detecting minor alterations in (2) almost identical images.  I wrote this because I found myself in a situation where I needed to detect minor changes in my architectural drawings and was having major troubles distinguishing small changes.


Image 1 - original image

<img align="left" width="50%" height="50%" src="https://images.squarespace-cdn.com/content/v1/5cc0708db10f257f085020f4/1567281818366-YCG8DOC0JET2YLL1BDD6/ke17ZwdGBToddI8pDm48kL5vtkVmuF_TfVXAjoajrn8UqsxRUqqbr1mOJYKfIPR7LoDQ9mXPOjoJoqy81S2I8N_N4V1vUb5AoIIIbLZhVYxCRW4BPu10St3TBAUQYVKcGQLJLq7bbn0dtpDTIRzKAA4rdzrVEJ6L0zdRX09DaLA9JivhSPEF_ntuZ80V9KbO/change2.png?format=500w">

Image 2 - altered image
<img align="right" width="50%" height="50%" src="https://images.squarespace-cdn.com/content/v1/5cc0708db10f257f085020f4/1567281805858-W839A0ZVYR9PU75HNQ86/ke17ZwdGBToddI8pDm48kL5vtkVmuF_TfVXAjoajrn8UqsxRUqqbr1mOJYKfIPR7LoDQ9mXPOjoJoqy81S2I8N_N4V1vUb5AoIIIbLZhVYxCRW4BPu10St3TBAUQYVKcGQLJLq7bbn0dtpDTIRzKAA4rdzrVEJ6L0zdRX09DaLA9JivhSPEF_ntuZ80V9KbO/change1.png?format=500w">

![shell interaction - options between circling altered pixels or outlining altered pixels](https://images.squarespace-cdn.com/content/v1/5cc0708db10f257f085020f4/1567281843393-BX02FCLLHJEQ0WJKNMYT/ke17ZwdGBToddI8pDm48kOk3VU_UcLbPt6sKQHMr_0dZw-zPPgdn4jUwVcJE1ZvWQUxwkmyExglNqGp0IvTJZUJFbgE-7XRK3dMEBRBhUpzyVHtn17tsIdnXyw-8O1nIpxy9NNPl5kDovg0S2g8XAMYQnj_ossJClYK0z3vSWXw/shell1.png?format=750w)
shell interaction - options between circling altered pixels or outlining altered pixels

![output image - written to user specified string location](https://images.squarespace-cdn.com/content/v1/5cc0708db10f257f085020f4/1567281860476-LJ00LTIFMBB09GQFI6IP/ke17ZwdGBToddI8pDm48kEJ4cOHrRQS9U6zMyLLMlBsUqsxRUqqbr1mOJYKfIPR7LoDQ9mXPOjoJoqy81S2I8N_N4V1vUb5AoIIIbLZhVYxCRW4BPu10St3TBAUQYVKcmad8uHYAF7-02Yclslrd79p8LOqe8r1XqsZNMHsW5qEE6Gv0YiTynNyofFZb7R3F/outline_1.png?format=750w)
output image - written to user specified string location

![image output of detection using cv::circle method](https://images.squarespace-cdn.com/content/v1/5cc0708db10f257f085020f4/1567281873321-6YHFH9ELJSU22MOHEF5D/ke17ZwdGBToddI8pDm48kHEbIFI6kGpWpDOyIBI-LOAUqsxRUqqbr1mOJYKfIPR7LoDQ9mXPOjoJoqy81S2I8N_N4V1vUb5AoIIIbLZhVYxCRW4BPu10St3TBAUQYVKcLCzQuhcYAiGX__w1xbbJRezcaedCH3OjVpziJmLA9HtPyZ41nyiyiJV7_Euhk0qK/circlel_1.png?format=750w)
image output of detection using cv::circle method


