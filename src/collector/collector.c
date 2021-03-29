//
// Created by Черных Никита Алекандрович on 3/25/21.
//

#include "collector.h"

Total *collect_size(File *file, size_t size) {
  Total *total = (Total *)calloc(1, sizeof(Total));
  if (!total) {
    return NULL;
  }

  Storage *storage = create_storage(size);
  if (storage == NULL) {
    return NULL;
  }

  fill_storage(storage, read_number, file);

  total->value = calculate_storage(storage, calculate_length);

  delete_storage(&storage);

  return total;
};