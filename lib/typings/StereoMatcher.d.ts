import { Mat } from "./Mat.d";

export class StereoMatcher {
  compute(left: Mat, right: Mat): Mat;
}

export class StereoBM extends StereoMatcher {
  constructor(numDisparities?: number, blockSize?: number);
}

export class StereoSGBM extends StereoMatcher {
  constructor(
    minDisparity?: number,
    numDisparities?: number,
    blockSize?: number,
    P1?: number,
    P2?: number,
    disp12MaxDiff?: number,
    preFilterCap?: number,
    uniquenessRatio?: number,
    speckleWindowSize?: number,
    speckleRange?: number,
    mode?: number
  );
}
