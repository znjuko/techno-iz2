//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#ifndef TECHNO_IZ2_COLLECTORPAR_H
#define TECHNO_IZ2_COLLECTORPAR_H

#include <stdbool.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <unistd.h>

#include "length_calculator.h"
#include "models.h"
#include "storage.h"

Total *collect_size(File *file, size_t size);

#endif  // TECHNO_IZ2_COLLECTORPAR_H
